import queue

# 전역 리스트로 여러 큐(queue)를 저장
angmu = [queue.Queue() for _ in range(101)]

# 문자열을 단어로 분리하여 해당하는 큐에 저장하는 함수
def slice_string(s, idx):
    words = s.split()  # 문자열을 공백으로 나누어 단어 목록으로 분리
    for word in words:
        angmu[idx].put(word)  # 각 단어를 해당하는 큐에 추가

def main():
    n = int(input())  # 앵무새 문장의 개수
    clear = True

    # 문장을 읽어들임, 마지막 문장은 목표 문장(L)
    for i in range(n + 1):  # 마지막 문장(L)을 포함
        tmp = input()  # 공백을 포함한 전체 줄을 읽음
        slice_string(tmp, i)  # 문장 처리 함수 호출

    # 목표 문장 L을 단어 하나씩 처리
    while not angmu[n].empty():  # 큐가 비어있지 않은 동안
        find = False  # L의 단어가 어떤 앵무새 문장에서 발견되었는지 확인
        for i in range(n):
            if angmu[i].empty():  # 이 앵무새의 문장이 이미 비어 있으면 넘어감
                continue
            if angmu[n].queue[0] == angmu[i].queue[0]:  # 첫 번째 단어가 일치하는지 확인
                angmu[n].get()  # L에서 단어 제거
                angmu[i].get()  # 앵무새의 문장에서 단어 제거
                find = True  # 단어를 찾았고 처리됨
                break  # 다음 L의 단어로 이동

        if not find:  # 단어가 어떤 앵무새 문장에서도 발견되지 않으면
            break  # 문장 L을 만들 수 없으므로 과정 중단

    # 모든 앵무새 문장이 완전히 처리되었는지 확인
    for i in range(n):
        if not angmu[i].empty():  # 어떤 앵무새 문장에 단어가 남아 있으면
            clear = False  # L을 만들 수 없음

    # 최종 결과 확인
    if clear and angmu[n].empty():  # 모든 문장이 처리되고 L도 완전히 일치하는 경우
        print("Possible")
    else:
        print("Impossible")

# 메인 함수 호출
if __name__ == "__main__":
    main()