#include <iostream>
#include <string>
#include <sstream>
#include <filesystem>
#include <unordered_map>
#include <memory>
#include <cassert>

#define TAB_SIZE 4

namespace fs = std::filesystem;

struct Entry
{
    Entry() { }
    Entry(
        const std::wstring& name,
        const std::wstring& path,
        const fs::directory_entry& entry)
        : name(name), path(path), entry(entry) { }

    virtual ~Entry() { }

    std::wstring name;
    std::wstring path;

    fs::directory_entry entry;
};

struct File : public Entry
{
    File() { }
    File(const std::wstring& name,
        const std::wstring& path,
        const fs::directory_entry& entry) : Entry(name, path, entry) { }
    ~File() { }
};

struct Directory : public Entry
{
    Directory() { }
    Directory(
        const std::wstring& name,
        const std::wstring& path,
        const fs::directory_entry& entry) : Entry(name, path, entry) { }
    ~Directory() { }

    std::unordered_map<std::wstring, std::shared_ptr<Directory>> subDirectories;
    std::unordered_map<std::wstring, std::shared_ptr<File>> files;

    int depth = 0;

    // ���� ���͸���  depth �� ������ ������.
    void update(bool excludeHiddenFiles);

    // ���͸��� ������ ���� ���� ���� toString �迭 getter �Լ���
    std::wstring string();
    std::wstringstream stringstream();

    bool containsFile(const File& file);
    bool containsSubDirectory(const Directory& directory);
};

void showDifferences(
    std::shared_ptr<Directory> a,
    std::shared_ptr<Directory> b)
{
    if (a->depth != b->depth)
    {
        return;
    }

    std::wstring prefix(a->depth * TAB_SIZE, L' ');
    std::wstring subPrefix((a->depth + 1) * TAB_SIZE, L' ');

    std::wcout << prefix << L"Difference In Directory " << "\"" << a->name << "\"" << std::endl;

    // ��� ����� �ӽ÷� ���� ��Ʈ��.
    std::wstringstream tempStream;

    for (const auto& pair : a->subDirectories)
    {
        auto directory = pair.second;
        if (b->containsSubDirectory(*directory))
        {
            // A�� B �� �� �ִ� ���͸��� ��� Ž����.
            showDifferences(directory, b->subDirectories[directory->name]);
        }
        else
        {
            // ��� Ž���� �켱���� �ϱ� ���� ȭ�鿡 ǥ�õ��� �ʴ� �ӽ� ��Ʈ���� ���.
            tempStream << subPrefix << "<Directory> " << "\"" << directory->name << "\"" << std::endl;
        }
    }

    // �ӽ� ��Ʈ���� ���� ���ڿ��� ��� ��ġ�� �ѱ�.
    // A���� �ְ� B���� ���� ���͸� �� ���Ͽ� ���
    std::wcout << prefix << L"[A contains but B not contains]" << std::endl;
    std::wcout << tempStream.str();

    for (const auto& pair : a->files)
    {
        auto file = pair.second;
        if (!b->containsFile(*file))
        {
            std::wcout << subPrefix << "<File> " << "\"" << file->name << "\"" << std::endl;
        }
    }

    // A���� �ְ� B���� ���� ���͸� �� ������ ���
    std::wcout << prefix << L"[B contains but A not contains]" << std::endl;

    for (const auto& pair : b->subDirectories)
    {
        auto directory = pair.second;
        if (!a->containsSubDirectory(*directory))
        {
            std::wcout << subPrefix << "<Directory> " << "\"" << directory->name << "\"" << std::endl;
        }
    }
    
    for (const auto& pair : b->files)
    {
        auto file = pair.second;
        if (!a->containsFile(*file))
        {
            std::wcout << subPrefix << "<File> " << "\"" << file->name << "\"" << std::endl;
        }
    }    
}


int main()
{
    // �ѱ� ��θ� �Է��� ����
    std::locale::global(std::locale("Korean"));

    wchar_t buf[1024];
    std::wcout << L"[���͸� A]: ";
    std::wcin.getline(buf, sizeof(buf));

    fs::path pathA(buf);

    std::wcout << L"[���͸� B]: ";
    std::wcin.getline(buf, sizeof(buf));

    fs::path pathB(buf);

    std::wcout << std::endl;

    fs::directory_entry entryA(pathA);
    fs::directory_entry entryB(pathB);

    std::shared_ptr<Directory> rootA = std::make_shared<Directory>(
        pathA.filename(),
        pathA,
        entryA);

    std::shared_ptr<Directory> rootB = std::make_shared<Directory>(
        pathB.filename(),
        pathB,
        entryB);

    rootA->update(false);
    rootB->update(false);

    showDifferences(rootA, rootB);

    return 0;
}

void Directory::update(bool excludeHiddenFiles)
{
    for (const auto& e : fs::directory_iterator(entry))
    {
        std::wstring path = e.path();
        std::wstring name = e.path().filename();

        // .git �̳� .vs ���� ���� ���͸� �� ������ ������.
        if (excludeHiddenFiles)
        {
            if (name.size() > 0 && name[0] == '.')
            {
                continue;
            }
        }        

        if (e.is_directory())
        {
            auto subDirectory = std::make_shared<Directory>(name, path, e);
            subDirectory->depth = depth + 1;
            subDirectories[name] = subDirectory;

            subDirectory->update(excludeHiddenFiles);
        }
        else
        {
            auto file = std::make_shared<File>(name, path, e);
            files[name] = file;
        }
    }
}

std::wstring Directory::string()
{
    return stringstream().str();
}

std::wstringstream Directory::stringstream()
{
    std::wstringstream stream;

    std::wstring prefix(depth * TAB_SIZE, ' ');
    stream << prefix << L"In Directory " << name << std::endl;    

    for (auto& pair : subDirectories)
    {
        auto name = pair.first;
        auto directory = pair.second;

        stream << prefix << name << std::endl;
        stream << directory->stringstream().str();
    }

    for (auto& pair : files)
    {
        auto name = pair.first;
        auto file = pair.second;

        stream << prefix << name << std::endl;
    }

    stream << std::endl;

    return stream;
}

bool Directory::containsFile(const File& file)
{
    return files.find(file.name) != files.end();
}

bool Directory::containsSubDirectory(const Directory& directory)
{
    return subDirectories.find(directory.name) != subDirectories.end();
}
