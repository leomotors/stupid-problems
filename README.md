# Stupid Problems

Problem Statements of Problems I wrote

**Fun Fact**: I have not write Vanilla JS for quite a long time (9 months to be exact) since abandoned [Website Vector Calculator](https://github.com/Leomotors/Website-Vector-Calculator)

## Stupid Problems Monorepo System

This monorepo consists of 3 part

- web - Web Template (Compiled to `dist-web` and Deploy to GitHub Pages)

- statements - Statements in TeX and build system in TypeScript

- src - Test Case Generating

## Scripts

```
yarn build <target>
```

- statements - Building Statements

- web - Building Web Dist from template

- gen - Compile test case generator and solution that are written in C++

```
yarn problem
```

Generate test case and solution with help of Python

```
yarn install-problem
```

Install problem to given location

## Credits

LaTeX template and aquagenlib.h by Senior at IPST Camp.

## To develop locally

- Install TeXLive (not sure which version, if error install earlier version)

- To compile statement with Thai Language, font [Sarabun](https://fonts.google.com/specimen/Sarabun?subset=thai) is required

- nodejs 16+ is recommended
