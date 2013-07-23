mem = {}

def D(S, N, k):
	if (S,N,k) in mem:
		return mem[(S,N,k)]
	elif N == 0 and S == 0:
		return 1
	elif S <= 0 or N * k < S:
		return 0
	else:
		ret = 0
		for i in range(min(k,S)):
			ret = (ret + D(S-i-1, N-1, k)) % 1000
		mem[(S,N,k)] = ret
		return ret

print (D(20,7,12)+D(31,6,4)+D(15,3,7)+D(111,17,7)+D(17,3,57)+D(1,2,2)+D(10,17,12)+D(9,3,0)) % 1000
