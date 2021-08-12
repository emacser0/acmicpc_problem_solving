ip = input()
ip_tokens = ip.split(':')
if "::" in ip:
    nl = 8 - len(ip_tokens)
    if len(ip_tokens) == 9:
        ip = ip.replace("::", ":")
    else:
        ip = ip.replace("::", '::' + ':' * nl)
    ip_tokens = ip.split(':')

for i in range(len(ip_tokens)):
    ip_tokens[i] = "0" * (4 - len(ip_tokens[i])) + ip_tokens[i]

print(':'.join(ip_tokens))