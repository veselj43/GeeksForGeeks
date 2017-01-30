from __future__ import print_function
try: input = raw_input
except NameError: pass

class Problem:
	def __init__(self, A, S):
		self.A = A
		self.S = S

	def __lowUp(self):
		if self.low == self.high - 1:
			return False

		self.s -= self.A[self.low]
		self.low += 1

		return True

	def __highUp(self):
		if self.high == len(self.A):
			return False

		self.s += self.A[self.high]
		self.high += 1

		return True

	def solve(self):
		self.s = self.A[0]
		self.low = 0
		self.high = 1

		while (self.low < len(self.A) - 1):
			if self.s < self.S:
				if not self.__highUp():
					return "-1"

			elif self.s > self.S:
				if not self.__lowUp():
					if not self.__highUp():
						return "-1"

			else:
				break

		if self.s != self.S:
			return "-1"

		return str(self.low + 1) + " " + str(self.high)


T = int(input())

for t in range(0, T):
	line = input().split()
	N = int(line[0])
	S = int(line[1])

	A = input().split()
	A = [int(x) for x in A]

	problem = Problem(A, S)
	print(problem.solve())
