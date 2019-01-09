package main

import "fmt"

func main() {
	list := []rune{'A', 'B', 'C'} //, 'D', 'E'}
	n := len(list)
	permute(n, list)
}
func permute(n int, list []rune) {
	if n == 1 {
		fmt.Println(string(list))
		return
	}

	//from 0 to n-2
	//if alter to n-1(i = n-1), you'll swap list[n-1] to list[n-1]
	for i := 0; i < n-1; i++ {
		fmt.Printf("run %x, n = %x\n", i, n)
		permute(n-1, list)
		if n%2 == 0 {
			fmt.Printf("swap list[%x] and list[%x]\n", i, n-1)
			list[i], list[n-1] = list[n-1], list[i]
		} else {
			fmt.Printf("swap list[0] and list[%x]\n", n-1)
			list[0], list[n-1] = list[n-1], list[0]
		}
	}
	fmt.Println("out of from")
	permute(n-1, list)
}
