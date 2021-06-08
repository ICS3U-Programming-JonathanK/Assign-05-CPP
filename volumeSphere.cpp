// Copyright (c) 2021 Jonathan Kene All rights reserved.
//
// Created by: Jonathan Kene
// Created on: June 8, 2021
// This program uses user defined functions to calculate the volume of a sphere

#include <iostream>
#include <cmath>

float Calculate(std::string operation, float firstNum) {
float result;

  if (operation == "volume") {
      result =  (static_cast<float>(4)/static_cast<float>(3) *
                 floor(M_PI * pow(firstNum, 3)));
    } else if (operation == "area") {
      result = 4 * floor(M_PI * pow(firstNum, 2));
    } else {
      result = -1;
    }
    return result;
}

int main() {
  std::string userFirstNumString;
  int userFirstNum;
  std::string quantity;
  float result;

while (quantity != "volume" || "area") {
  // ask the user whether they wish to have the volume or area
  std::cout << "Please type in whether you'd like to calculate the"
               " volume or the area (type 'volume' or 'area'): ";
  std::cin >> quantity;
  // these two function asks for the radius from the user
  if (quantity == "volume") {
    std::cout << "Today, we will calculate the volume of a sphere" << std::endl;
    std::cout << "Enter the radius: ";
    std::cin >> userFirstNumString;

    try {
      userFirstNum = std::stof(userFirstNumString);
      if (userFirstNum <= 0) {
              std::cout << userFirstNum << " is not"
                                           " a positive number" << std::endl;
          } else {
            result = Calculate(quantity, userFirstNum);
            std::cout << "The volume is " << printf("%.1f", result) <<
                         " cm^3" << std::endl;
          }
    } catch (std::invalid_argument) {
      // The user did not enter an integer.
      std::cout << "\n";
      std::cout << "Please enter a valid number.\n";
    }

  } else if (quantity == "area") {
    std::cout << "Today, we will calculate the area of a sphere" << std::endl;
    std::cout << "Enter the radius: ";
    std::cin >> userFirstNumString;

    try {
      userFirstNum = std::stof(userFirstNumString);
      if (userFirstNum <= 0) {
              std::cout << userFirstNum << " is not"
                                           " a positive number" << std::endl;
          } else {
            result = Calculate(quantity, userFirstNum);
            std::cout << "The area is " << printf("%.2f", result) <<
                         " cm^2" << std::endl;
          }
    } catch (std::invalid_argument) {
      // The user did not enter an integer.
      std::cout << "\n";
      std::cout << "Please enter a valid number.\n";
    }
  } else {
    std::cout << "Invalid input" << std::endl;
    continue;
  }
}
}
