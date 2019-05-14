## Bitmap Parser

### Hey, what is this?
This project is a **very simple** Bitmap parser.

The goal here is to understand how an image file works behind the scenes. I chose the Bitmap format because it often does not contain compression, so it is an easy starting point.

### Can I use it in my project?
Well, probably not. 😟 Unfortunately, it does not cover all aspects and details of a Bitmap image. So, this can easily fail when applied to any other image different from the original one. Perhaps one day? I'm planning to improve it whenever I have some time.

However, I'm sure you can easily find any _production-ready_ Bitmap parser around.

### What is a parser?
A parser can have slight differences in its meaning depending on the context.

In this context, a parser is a program that reads a raw file and turns it into a data structure that - in theory - could be reused by any other program. Since this parser is written in C, it could be used only by other programs that use C.

### How does it work?
Yayy, I'm glad you asked! 🌟 Let's learn a bit more about how an image work?

#### An image is more than many painted pixels on the screen
Whenever you open an image in your computer, you see many (millions) painted pixels (dots) in your screen. This is how you see something and say _"hey, that's an image!"_.

However, did you already wonder how an image work under the hood? You probably already heard that a computer can only handle binaries. It means that **everything** inside a computer must be translated into a set of **0**'s and **1**'s.

The same thing happens to an image. An image, under the hood, is a set of binary numbers.

Believe it or not, the following output represents an image in your computer:

```
01000010 01001101 01011010 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00110110 00000000 00000000 00000000 00101000 00000000 00000000 00000000 00000000 00000011 00000000 00000000 00000000 00000011 00000000 00000000 00000000 00000001 00000000 00011000 00000000 00000000 00000000 00000000 00000000 00000000 00100100 00000000 00000000 00000000 00010011 00001011 00000000 00000000 00010011 00001011 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 11111111 11111111 00000000 00000000 00000000 11111111 00000000 00000000 00000000 00000000 00000000 11111111 11111111 11111111 00000000 11111111 00000000 11111111 11111111 11111111 00000000 00000000 00000000 00000000 11111111 00000000 00000000 11111111 11111111 11111111 00000000 00000000 11111111 00000000 00000000 00000000
```

Weird, huh? Yeah, it is, indeed! However, keep in mind: **everything in a computer is a set of binary numbers, just like this one**.

#### So, how is this set of binary converted into a visual image?
That's the best part!

There must be a way to convert all these bytes to a painted image on the screen. There must be a **standard** that says what each byte represents.

In fact, there is a standard. These standards are called **specifications**.

Almost everything in a computer have a specification. Image formats and network protocols are good examples. The specification is originally created by the "inventor" of that format.

A specification **is not an algorithm implementation**. It is just a set of paragraphs (a text) explaining the theory behind that format - how it should behave.

So, based on the specification of something, different people create different algorithm implementations - always trying to make the best solution.

```
This explaining text needs to be completed
```
