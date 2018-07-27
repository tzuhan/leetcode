package main

import "fmt"

type node struct {
	head int
	tail int
}

func main() {
	array := []int{-2, -3, -3, 7, -3, 0, 5, 0, -8, -4, -1, 2}
	fmt.Println(longestConsecutive(array))
	array = []int{0, 3, 7, 2, 5, 8, 4, 6, 0, 1}
}
func longestConsecutive(nums []int) int {
	union_node := make(map[int]node)
	max := 0
	for _, val := range nums {
		nodePre, okPre := union_node[val-1]
		_, ok := union_node[val]
		nodeSuf, okSuf := union_node[val+1]
		if ok {
			continue
		} else {
			head, tail := val, val
			countPre, countSuf := 0, 0
			if okPre {
				countPre = nodePre.tail - nodePre.head + 1
				if head > nodePre.head {
					head = nodePre.head
				}
			}
			if okSuf {
				countSuf = nodeSuf.tail - nodeSuf.head + 1
				if tail < nodeSuf.tail {
					tail = nodeSuf.tail
				}
			}
			count := 1 + countPre + countSuf
			union_node[val] = node{head, tail}
			if head != val {
				union_node[head] = union_node[val]
			}
			if tail != val {
				union_node[tail] = union_node[val]
			}
			if max < count {
				max = count
			}
		}
	}
	return max
}
