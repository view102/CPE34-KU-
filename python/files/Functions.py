def find(a, n):
      ''' return the index i where a[i] = n, -1 otherwise'''
  len_a = len(a)
  res = -1
  for i in range(len_a):
    if a[i] == n:
      return i
  return -1

def findMax(a):
  ''' return the index i where a[i] is max '''
  mymax = -9999999999
  len_a = len(a)
  res = -1
  for i in range(len_a):
    if a[i] > mymax:
      mymax = a[i]
      res = i
  return res

def swap(a, i, j):
  tmp = a[i]
  a[i] = a[j]
  a[j] = tmp

def mySort(a, q):
  '''sort list a, and list q will swap according to sorted a'''
  len_a = len(a)
  for i in range(len_a):
    #print(a)
    b = a[i:]
    j = findMax(b)
    #print(f' i:{i}, b: {b}, j:{j}')
    swap(a, i, i+j)
    swap(q, i, i+j)

def getPosInt():
  n = 0
  while n < 1:
    n = int(input('Input a positive integer: ').strip())
  return n

def printStr(a, b):
  for i in range(b):
    for j in range(i):
      print(' ')

def printBarChart(n):
  for i in range(n):
    for j in range(10):
      print(j, end='')
  print()

def getFloat(prompt):
  return float(input(prompt).strip())

def printLine(s, m, b):
  print(s, end='')
  print(f' y = {m}x + {b}')

def toLower(s):
  res = ''
  for i in s:
    if i >= 'A' and i <= 'Z':
      res = res + chr(ord('a') + (ord(i) - ord('A')))
    else:
      res = res + i
  return res

def isPalindrome(s):
  # base case, only zero or one character left
  if len(s) == 0 or len(s) == 1:
    return True
  ## general case now
  # 1. check whether start and end chars of s is the same
  res = True if s[0] == s[len(s)-1] else False
  # 2. create new ss without start and end chars from s
  ss = s[1:len(s)-1]
  # 3. check whether the `ss` is palindrome
  return res and isPalindrome(ss)

def isPalindrome2(s):
  """
  Check whether a string s is palindrome?
  1.1) if s is a null string, s is palindrome
  1.2) if s composes of only one char, s is palindrome
  2) we check whether the first and the last chars, i.e. s[0] and s[len(s)-1] 
     are the same, AND re-check whether the string s[1:len(s)-1] is palindrome? 
  """
  print(f'DEBUG: {s}')
  if len(s)==0:   # base case 1.1)
    return True
  if len(s)==1:   # base case 1.2)
    return True
  # case 2) 
  return s[0]==s[len(s)-1] and isPalindrome2(s[1:len(s)-1])

def isPrime(n):
  res = True
  for i in range(2, n//2 + 1):
    if n%i == 0:
      res = False
      break
  return res

def feb(y):
  ''' check whether that y has 29 or 28 days
      return True if 29, False otherwise '''
  if (y%4==0 and y%100!=0) or (y%400==0):
    return True
  return False

def daysInMonth(mo, y): # days in month/year
  '''
    given integer month and year, return the nb. of days in that month'''
  m = [0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
  if mo==2 and feb(y):
    return 29
  return m[mo]

def mStr(m):
  mm = ['', 'Jan', 'Feb', 'Mar', 'Apr', 'May', 'Jun', 'Jul', 'Aug', 'Sep', 'Oct', 'Nov', 'Dec']
  return mm[m]

def getInput():
  s = 0
  while s <= 0:
    s = int(input('Input Unix Time in second(s): ').strip())
  return s

def isLeapYear(y):
  if (y%4==0 and y%100!=0) or (y%400==0):
    return True
  return False

def dayInYear(y):
  if isLeapYear(y):
    return 366
  return 365

def checkDate(date1, date2):
  '''
    will determine and return date1 which comes before date2
  '''
  d1,m1,y1 = date1
  d2,m2,y2 = date2
  if y1 > y2:
    return date2, date1
  elif y1==y2 and m1>m2:
    return date2, date1
  elif y1==y2 and m1==m2 and d1>d2:
    return date2, date1
  return date1, date2

def isprime(z,sum):
  if z==2:
    return True
  if z==1:
    return False
  for x in range(2,z):
    if z%(x)==0 and z>2:
      return False
  if z%(x)!=0 and z>2:
    return True

def fac(n):
  fac=1
  while n>0:
    fac=fac*n
    n=n-1
  return fac

def findMaxv2(a):
  ''' return the index i where a[i] is max '''
  mymax = -9999999999
  len_a = len(a)
  res = -1
  for i in range(len_a):
    if a[i] > mymax:
      mymax = a[i]
      res = i
  return mymax

#ord() change char to int
#chr() change int to ASCII

def findmin(a):
  mymin=99999999999999999999999
  len_a =len(a)
  res=-1
  for i in range(len_a):
    if a[i]<mymin:
      mymin=a[i]
      res=i
  return res

def findminv2(a):
  mymin=99999999999999999999999
  len_a =len(a)
  res=-1
  for i in range(len_a):
    if a[i]<mymin:
      mymin=a[i]
      res=i
  return mymin

def mysortv2(a):
  len_a=len(a)
  for i in range(len_a):
    b=a[i:]
    j=findmin(b)
    swap(a, i, i+j)

def dectohex()
  dec = int(input('Input Decimal: '))
  octal = ''
  while (dec > 0):
    octal = str(dec%8) + octal
    dec = dec // 8
  print(octal)

def zeroMat(a):
  c = []
  for i in range(len(a)):
    row = []
    for j in range(len(a[i])):
      row.append(0)
    c.append(row)
  return c

def printMat(a):
  for i in range(len(a)):
    for j in range(len(a[i])):
      print(f'{a[i][j]:4d}', end='')
    print()
  print()

def addMat(a, b):
  c = zeroMat(a)
  for i in range(len(a)):
    for j in range(len(a[i])):
      c[i][j] = a[i][j] + b[i][j]
  return c

def countNbFollowers(f):
  uname, c = [],[]
  for i in range(len(f)):
    uname.append(f[i][0])
    tmp = 0
    for j in range(len(f[i][1])):
      tmp += 1
    c.append(tmp)
  return uname, c

def sortFollowers(uname, c):
  p,q =[],[]
  while len(c)>0:
    maxFol = max(c)
    maxFolCount = c.count(maxFol)
    for k in range(maxFolCount):
      i = c.index(maxFol)
      p.append(uname.pop(i))
      q.append(c.pop(i))
    #print(p,q)
  return p,q
#', '.join(max_followers)    koi, noon, wii

def roman(romanum):
    if romanum>=1000:
        romanum=romanum-1000
        sym='M'
        return sym + roman(romanum)
    elif romanum>=900:
        romanum=romanum-900
        sym='CM'
        return sym + roman(romanum)
    elif romanum>=500:
        romanum=romanum-500
        sym='D'
        return sym + roman(romanum)
    elif romanum>=400:
        romanum=romanum-400
        sym='CD'
        return sym + roman(romanum)
    elif romanum>=100:
        romanum=romanum-100
        sym='C'
        return sym + roman(romanum)
    elif romanum>=50:
        romanum=romanum-50
        sym='L'
        return sym + roman(romanum)
    elif romanum>=45:
        romanum=romanum-45
        sym='XLV'
        return sym + roman(romanum)
    elif romanum>=40:
        romanum=romanum-40
        sym='XL'
        return sym + roman(romanum)
    elif romanum>=10:
        romanum=romanum-10
        sym='X'
        return sym + roman(romanum)
    elif romanum>=9:
        romanum=romanum-9
        sym='IX'
        return sym + roman(romanum)
    elif romanum>=5:
        romanum=romanum-5
        sym='V'
        return sym + roman(romanum)
    elif romanum>=4:
        romanum=romanum-4
        sym='IV'
        return sym + roman(romanum)
    elif romanum>=1:
        romanum=romanum-1
        sym='I'
        return sym + roman(romanum)
    else:
        return ""

print(roman(82))