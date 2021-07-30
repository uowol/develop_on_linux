import requests
URL = 'https://www.airforce.mil.kr/user/emailPicSaveEmail.action'

# 보내는 이의 정보를 입력받습니다.
zipCode = '15623'
addr1 = "경기도 안산시 상록구 감골2로 11"
addr2 = "예누림 아파트 511동 305호"
sender = '김췌누'

# 편지의 제목을 설정합니다.
title = "'{}'님이 보낸 편지입니다.".format(sender)

# 편지의 내용을 설정합니다.
contents = """
세현이에게 편지가 안온다는 소식을 듣고 너무 슬픈 나머지 간단한 프로그램을 만들어봤어 :)\r\n
역시 편지를 안쓰게 되는 가장 큰 이유는 귀찮음이 아닐까... 하는 마음에서 사용자의 입장에서 조금 더 쓰기 편하게 해보려 했는데 잘 된건지는 모르겠다.\r\n
이 프로그램이 너의 덥고 지친 훈련소 생활에 조금이나마 힘이 되었으면 좋겠어 (」^ロ^)」
"""
contents_tail = '　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　 　　　　　　　　　　　　　　　　　　　　　　　　　　　　　 \r\n== 본 편지는 받는 이의 취향을 고려하여 봇이 작성하였습니다. =='


cookies = {
    'JSESSIONID': 'oNkEfzMB45F1kXZfvFArDUDkPJlomcxhDXM7wKYR9AqX9yt7pjpIJ3cRcqbBk8xv.AF1302_servlet_CONT21'
}
data = {
    'siteId': 'last2', 
    'command2' : 'writeEmail',
    "senderZipcode": "15623",
    "senderAddr1": "경기도 안산시 상록구 감골2로 11",
    "senderAddr2": "예누림 아파트 511동 305호",
    "senderName": sender,
    "relationship" : "친구 봇",
    "title" : title,
    "contents" : contents+contents_tail,
    "password": "SehyeonTheLove",
}

res = requests.post(URL, data=data, cookies=cookies, verify=False)

print(res.status_code)
# print(res.text)
