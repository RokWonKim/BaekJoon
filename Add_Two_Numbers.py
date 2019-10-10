def Nodenum(ll):                #각각의 연결리시트들의 value값 다 뽑아 합쳐서 정수로 만들어 반환
    arr = []
    while ll:
        arr += [str(ll.val)]
        ll = ll.next
    arr.reverse()
    return int("".join(arr))
class ListNode:                 #연결리스트 만들기 및 노드 추가하기
    def __init__(self, x):
        self.val = x
        self.next = None
    def insertnode(self, head, x):
        while head.next:
            head = head.next
        head.next = ListNode(x)
class Solution(object):             #연결리스트 2개를 더하고 str로 만들어 각각의 인덱스를 뒤에서 부터 연결리스트에 넣어줌
    def addTwoNumbers(self, l1, l2):
        add = str(Nodenum(l1) + Nodenum(l2))
        l1 = ListNode(add[-1])     # 매우 중요! 주소 안의 값을 바꾸는게 아니라 주소 자체를 넘어가는거여서
        l3 = l1                    # ㅣ1이 넘어가도 ㅣ3는 바뀌지 않음
        for i in range(len(add) - 2, -1, -1):
            l1.next = ListNode(add[i])
            l1 = l1.next

        return l3

l1 = ListNode(2)
l1.insertnode(l1,4)
l1.insertnode(l1,3)

l2 = ListNode(5)
l2.insertnode(l2,6)
l2.insertnode(l2,4)

ll = Solution()
l3 = ll.addTwoNumbers(l1,l2)

while l3:
    print(l3.val, end =' ')
    l3 = l3.next