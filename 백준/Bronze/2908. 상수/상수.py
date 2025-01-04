nums = input().split()

re_nums = [n[::-1] for n in nums]

if (re_nums[0] > re_nums[1]):
  print(re_nums[0])
else:
  print(re_nums[1])
