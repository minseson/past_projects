## Java JUnit practice

- [Goals](#goals)
- [Description](#description)
- [Specification](#specification)

## Goals

This program is aimed to:
- Understand how to model decision-making behavior in UML
  - Create a UML activity diagram expressing the payout-deciding behavior used in this assignment.
- Understand how to create a unit test suite for a Java class
  - Consider the logical aspects of designing unit tests for a slot machine
  - Implement your test cases using JUnit 5
- Understand how to implement a design specification and validate it with unit tests
  - Implement a slot machine using the provided specifications

## Description

This program follows the the rules for the slot machines, and several developers have implemented versions of their slot machine that claim to correctly implement these rules. Your task is to develop a comprehensive set of unit tests to verify these implementations' correctness. In addition, you will provide your own implementation of the rules (validated by your own test cases, of course).

## Specification

Each implementation of a Slippery Slot Machine provides a public interface of two methods, and follows a set of payoff rules (described below).

#### The SlipperySlot rules

Each implementation of a Slippery Slot Machine is supposed to function according to the following rules: 
- A single play costs $2 and produces a set of five numbers taking values between 1 and 50 (inclusive) as uniformly-distributed, i.i.d. random variables.
- Once the five number spin has been generated, an associated payoff is computed by applying the rules below.
  - Rules 1-5 are mutually-exclusive -- at most one of these rules may apply at a time, and each rule may apply exactly once per spin (choose the highest-paying rule which applies).
  - Rules 6-8 may apply in combination with any of rules 1-5 or with each other, but at most once per spin (each).
  
The payout rules are:
1. If all five numbers are the same, pay $1000000.
2. If four numbers are the same (and the fifth number does not match), pay $10000.
3. If three numbers are the same AND the remaining two numbers match each other (but not the previous three -- a "full house"), pay $5000.
4. If three numbers are the same and the remaining two numbers are different (both from the set of three and each other), pay $100
5. If any two numbers are the same (but no previous rule applies), pay $10.
  - Note that rule 5 is applied at most once per spin, even if the spin contains two distinct pairs of matching numbers.
6. If one or more of the five numbers is a perfect (integer) square, add $7 to the payout (at most once per spin).
7. If one or more of the five numbers is 42, add $2 (at most once per spin).
8. If one or more of the five numbers is a power of two, add $3 (at most once per spin).

#### The SlipperySlot API

Each implementation of a SlipperySlot enacts the rules above through the following two public methods:
- `int[] pullTheLever()`
  - This method generates a single spin of the slot machine. Its return value is an array of five integer values, each lying between 1 and 50 (inclusive) and chosen to be appropriately random.

- `int payOff( int[] values )`
  - This method takes as input an array representing a single spin (same form as the return value of `pullTheLever()`). It's return value is the correct payoff of that spin, computed according to the rules above.
