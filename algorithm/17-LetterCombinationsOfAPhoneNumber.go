package main

import "fmt"

//2 => a,b,c (97, 98, 99) 2 + 95, 2+96, 2+97
//3 => d,e,f (100, 101, 102) 3 + 95+2*(3-2), 3+98, 3+99
//4 => g,h,i (103, 104, 105) 4 + 95+2*(4-2), 4+100, 4+101
//...

func main() {
	result := letterCombinations("2")
	fmt.Println(result)
	result = letterCombinations("123")
	fmt.Println(result)
	result = letterCombinations("1023")
	fmt.Println(result)
}

func letterCombinations(digits string) []string {
	result := []string{}
	for _, val := range digits {
		fmt.Println(val - '0')
		result = letterCombinationsHelper(val-'0', result)
	}
	return result
}

func letterCombinationsHelper(num rune, result []string) []string {
	var f, s, t rune = 95 + 2*(num-2), 96 + 2*(num-2), 97 + 2*(num-2)
	candidate := []rune{}
	if num >= 2 && num <= 6 {
		candidate = []rune{num + 95 + 2*(num-2), num + 96 + 2*(num-2), num + 97 + 2*(num-2)}
	} else if num == 7 {
		candidate = []rune{num + 95 + 2*(num-2), num + 96 + 2*(num-2), num + 97 + 2*(num-2), num + 98 + 2*(num-2)}
	} else if num == 8 {
		candidate = []rune{num + 96 + 2*(num-2), num + 97 + 2*(num-2), num + 98 + 2*(num-2)}
	} else if num == 9 {
		candidate = []rune{num + 96 + 2*(num-2), num + 97 + 2*(num-2), num + 98 + 2*(num-2)}
	} else if num == 1 {
		candidate = append(candidate, rune('*'))
	} else if num == 0 {
		candidate = append(candidate, rune(' '))
	}

	if len(result) == 0 {
		for _, can := range candidate {
			result = append(result, string(can))
		}
	} else {
		new_result := []string{}
		for _, val := range result {
			for _, can := range candidate {
				new_result = append(new_result, val+string(can))
			}
		}
		result = new_result
	}
	for _, val := range result {
		fmt.Printf("%v, ", string(val))
	}
	fmt.Println()
	return result
}
