# eval_ex_fraction

[Baekjoon No.30855 problem](https://www.acmicpc.net/problem/30855)

evaluation of extension fraction and make irreducible fraction

We use Flex and Bison for parsing the input string

# requirements
- Flex
- Bison
- Make

# compile
```
make all
```

# example

## example1
### input
```
(1 2 3)
```
### output
```
Op(mkFraction)
   Int(1)
   Int(2)
   Int(3)

Answer: 5 / 3
```

## example2
### input
```
(2 ( 3 4 5) 7)

```
### output
```
Op(mkFraction)
   Int(2)
   Op(mkFraction)
      Int(3)
      Int(4)
      Int(5)
   Int(7)

Answer: 89 / 35
```
## example3
### input
```
( ( 1 2 4 ) ( 5 2 3 ) ( 4 3 ( 2 7 3 ) ) )
```
### output
```
Op(mkFraction)
   Op(mkFraction)
      Int(1)
      Int(2)
      Int(4)
   Op(mkFraction)
      Int(5)
      Int(2)
      Int(3)
   Op(mkFraction)
      Int(4)
      Int(3)
      Op(mkFraction)
         Int(2)
         Int(7)
         Int(3)

Answer: 991 / 366
```
