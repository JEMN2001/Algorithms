def factorial(x):
	if x < 0:
		return 0
	elif x == 0:
		return 1
	else:
		return factorial(x-1)*x
while (True):
	x = raw_input("Ingrese un numero: ")
	if x == "":
		break;
	else:
		print factorial(int(x))

