# Bitmap Parser

## 1. What is this project?
This project is a **very simple** Bitmap parser.

The goal here is to understand how an image file works behind the scenes. I chose the Bitmap format because it often does not contain compression, so it is an easy starting point.

## 2. Can I use it as a library for any other project?
Well, probably not. 😟 Unfortunately, it does not cover all aspects and details of Bitmap's specification. So, this can easily fail when used in any other place rather than the original development environment.

However, I'm sure you can easily find any _production-ready_ Bitmap parser around.

## 3. Parser? What is this?
A parser can have slight differences in its meaning depending on the context.

In this context, a parser is a program that reads a raw file and turns it into a data structure that - in theory - could be reused by any other program. Since this parser is written in C, it could be used only by other programs that use C.

## 4. How does it work?
Yayy, I'm glad you asked! 🌟 Let's learn a bit more about how an image work?

### 4.1. Is an image only a bunch of pixels painted on the screen?
Whenever you open an image in your computer, you see many (millions) painted pixels in your screen. These pixels make up an image in your screen. This is how you see something and say _"hey, that's a nice picture!"_.

However, did you already wonder how an image work behind the scenes? How could an image navigate through the network? You probably already heard that a computer can only handle binaries. It means that **everything** inside a computer must be translated into a set of **0**'s and **1**'s.

The same thing happens to an image. An image, under the hood, is a set of binary numbers.

Believe it or not, the following output represents an image in your computer:

```
01000010 01001101 01011010 00000000 00000000 00000000 00000000 00000000
00000000 00000000 00110110 00000000 00000000 00000000 00101000 00000000
00000000 00000000 00000000 00000011 00000000 00000000 00000000 00000011
00000000 00000000 00000000 00000001 00000000 00011000 00000000 00000000
00000000 00000000 00000000 00000000 00100100 00000000 00000000 00000000
00010011 00001011 00000000 00000000 00010011 00001011 00000000 00000000
00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000
00000000 00000000 00000000 11111111 11111111 00000000 00000000 00000000
11111111 00000000 00000000 00000000 00000000 00000000 11111111 11111111
11111111 00000000 11111111 00000000 11111111 11111111 11111111 00000000
00000000 00000000 00000000 11111111 00000000 00000000 11111111 11111111
11111111 00000000 00000000 11111111 00000000 00000000 00000000
```

When you send an image to your friends over the network, this is **exactly** what navigates through the cables.

Weird, huh? Yeah, it is, indeed! However, keep in mind: **everything in a computer is a set of binary numbers. Everything.**.

### 4.2. So, how is this set of binary converted into a visual image?
That's the best part!

There must be a way to convert all these binary numbers to a painted image on the screen. There must be a **standard** that says what each number represents.

In fact, there is a standard. These standards are called **specifications**.

Almost everything in a computer have a specification. Image formats and network protocols are good examples. The specification is originally created by the "inventor" of that format.

A specification **is not an algorithm implementation**. It is just a set of paragraphs (a huge text) explaining the concept behind that theory - how it should behave.

So, based on the specification of something, different people create different algorithm implementations - always trying to make the best solution.

```
This explaining text needs to be completed
```
