Website_num, password_num = map(int, input().split())
site_password = {}
for i in range(Website_num):
    site, password = map(str, input().split())
    site_password[site] = password
for i in range(password_num):
    find_password = input()
    print(site_password[find_password])