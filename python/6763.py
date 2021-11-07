A, B = eval('int(input()),' * 2)
if A >= B:
    print("Congratulations, you are within the speed limit!")
else:
    fine = 100
    if B - A > 20:
        fine = 270
    if B - A > 30:
        fine = 500
    print("You are speeding and your fine is ${}.".format(fine))