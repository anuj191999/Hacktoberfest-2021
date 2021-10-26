# Python program to check if there exists a pythagorean triplet
def checkTriplet(arr, n):
	for i in range(n):
		arr[i] = arr[i] * arr[i]

	arr.sort()

	for i in range(n - 1, 1, -1):
		s = set()
		for j in range(i - 1, -1, -1):
			if (arr[i] - arr[j]) in s:
				return True
			s.add(arr[j])
	return False

# Driver Program
arr = [3, 2, 4, 6, 5]
n = len(arr)
if (checkTriplet(arr, n)):
	print("Yes")
else:
	print("No")

