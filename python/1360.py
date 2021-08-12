n = int(input())
text = []
cmd_list = []


def redo(param, t, last_index):
    first_index = last_index
    while first_index > 0 and \
        cmd_list[first_index][2] > t - param:
        first_index -= 1

    for i in range(first_index, last_index + 1):
        if cmd_list[i][2] < t - param:
            continue
        if cmd_list[i][0] and i - 1 >= 0:
            undo(cmd_list[i][1], cmd_list[i][2], i - 1)
        elif not cmd_list[i][0]:
            text.append(cmd_list[i][1])


def undo(param, t, last_index):
    for i in range(last_index, -1, -1):
        if cmd_list[i][2] < t - param:
            break
        if cmd_list[i][0] and i - 1 >= 0:
            redo(cmd_list[i][1], cmd_list[i][2], i - 1)
            pass
        elif not cmd_list[i][0] and len(text):
            text.pop()


for i in range(n):
    cmd, param, t = input().split(' ')
    cmd = 0 if cmd == "type" else 1
    t = int(t)

    if cmd:
        param = int(param)
        undo(param, t, i - 1)
    else:
        text.append(param)

    cmd_list.append((cmd, param, t))

print(''.join(text))