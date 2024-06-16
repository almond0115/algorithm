from typing import List


class Solution:
    def groupThePeople(self, groupSizes: List[int]) -> List[List[int]]:
        # 같은 그룹 크기끼리 분류?
        # 인덱스 값을 저장하므로 이 부분 유의
        sizeList = set()
        for gs in groupSizes:
            sizeList.add(gs)
        
        sizeList = list(sizeList)
        result = []

        for sizeIdx in sizeList:
            tempList, splitList = [], []
            for i in range(len(groupSizes)):
                if groupSizes[i] == sizeIdx:
                    tempList.append(i)
            
            # 리스트 크기가 해당 사이즈보다 클 경우
            if len(tempList) > sizeIdx:
                # 사이즈에 맞게 리밸런싱
                for i in range(1, len(tempList)+1):
                    splitList.append(tempList[i-1])
                    if i % sizeIdx == 0:
                        result.append(splitList)
                        splitList = []
                continue
                    

            result.append(tempList)

        return result