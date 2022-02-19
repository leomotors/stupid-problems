# Stupid Problems

Problem Statements of Problems I wrote

**Fun Fact**: I have not write Vanilla JS for quite a long time (9 months to be exact) since abandoned [Website Vector Calculator](https://github.com/Leomotors/Website-Vector-Calculator)

## Stupid Problems Monorepo System

This monorepo consists of 3 part

- src - Test Case Generator
- statements - Statements in TeX
- web - Web Template (Compiled to `dist-web` and Deploy to GitHub Pages)

# ➡️ Scripts

## yarn build \<target\>

Build target, this build system is powered by TypeScript

- statements - Building Statements

- web - Building Web Dist from template

- gen - Compile test case generator and solution that are written in C++

## yarn problem

Generate test case and solution with help of Python

## yarn install-problem

Install problem to given location

# 🙇‍♂️ Credits

`aquagenlib.h` by Senior at IPST Camp, [plumsirawit](https://github.com/plumsirawit) if I don't remember wrong.

LaTeX Template forwarded from my friends, ~~so I don't know where it comes from~~ from
[programming-in-th/statements](https://github.com/programming-in-th/statements/blob/master/templates/style.sty)
_Note that LaTex Template in this repositories is modified from original_

## Notes

Testcase generated from here is target directly to be compatible with
[cocoa-grader](https://github.com/Leomotors/cocoa-grader)

## To develop locally

- Install TeXLive (not sure which version, if error install earlier version)

- To compile statement with Thai Language, font [Sarabun](https://fonts.google.com/specimen/Sarabun?subset=thai) is required

- nodejs 16+ is recommended
