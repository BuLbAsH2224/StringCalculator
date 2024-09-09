#pragma once
#include "settings.h"

char ArithmeticSigns[]{ '+' ,'-', '*', '/','^'};

bool thisIsArithmetiсSign(char &sign) {
    for (int i = 0; i < std::size(ArithmeticSigns); i++) {
        if (sign == ArithmeticSigns[i]) {
            return true;
        }
    }
    return false;
}

auto ParsingAnExample(std::string& example) {
    std::vector<std::string> ParsingExample;
    std::string ValueBeforeSign;
    for (int i = 0; i < example.length(); i++) {
            if (thisIsArithmetiсSign(example[i]) == true && example[i-1] !=  '(') {
                ParsingExample.push_back(ValueBeforeSign);
                ParsingExample.push_back(std::string(1, example[i]));
                ValueBeforeSign = "";
            }
            else {


                ValueBeforeSign += std::string(1, example[i]);
                if (i == example.length() - 1) {
                    ParsingExample.push_back(ValueBeforeSign);
                }

            }
        
    }
    return ParsingExample; 
}


double StringToDouble(std::string str) {
    std::string newStr = str;
    double x = 0;
    if (newStr.find("sin") != std::string::npos) {
        newStr = newStr.substr(4);
        newStr = newStr.substr(0, newStr.length() - 1);
        x = sin(std::stod(newStr));
        return x;
    }
    else  if (newStr.find("cos") != std::string::npos) {
        newStr = newStr.substr(4);
        newStr = newStr.substr(0, newStr.length() - 1);
        x = cos(std::stod(newStr));
        return x;
    }
    else  if (newStr.find("abs") != std::string::npos) {
        newStr = newStr.substr(4);
        newStr = newStr.substr(0, newStr.length() - 1);
        x = abs(std::stod(newStr));
        return x;
    }
    else  if (newStr.find("sqrt") != std::string::npos) {
        newStr = newStr.substr(5);
        newStr = newStr.substr(0, newStr.length() - 1);
        x = sqrt(std::stod(newStr));
        return x;
    }
    else  if (newStr.find("ceil") != std::string::npos) {
        newStr = newStr.substr(5);
        newStr = newStr.substr(0, newStr.length() - 1);
        x = ceil(std::stod(newStr));
        return x;
    }
    else  if (newStr.find("exp") != std::string::npos) {
        newStr = newStr.substr(4);
        newStr = newStr.substr(0, newStr.length() - 1);
        x = exp(std::stod(newStr));
        return x;
    }
    else  if (newStr.find("log") != std::string::npos) {
        newStr = newStr.substr(4);
        newStr = newStr.substr(0, newStr.length() - 1);
        x = log(std::stod(newStr));
        return x;
    }
    else  if (newStr.find("fac") != std::string::npos) {
        newStr = newStr.substr(4);
        newStr = newStr.substr(0, newStr.length() - 1);
        x = std::stod(newStr);
        double y = 1;
        for (double i = 1; i <= x; i++) {
                y = y * i;
        }
        return y;
    }
    else  if (newStr == "PI") {
        x = 3.1415926535;
        return x;
    }
    else  if (newStr == "(-PI)") {
        x = 3.1415926535;
        return x;
    }
    else  if (newStr.find("(") != std::string::npos) {
        newStr = newStr.substr(1);
        newStr = newStr.substr(0, newStr.length() - 1);
        x =  std::stod(newStr);
        return x;
    }
    else {
        x = std::stod(newStr);
        return x;
    }
    //std::stof(Hel)
    return 0;
}

std::string CalculateWithAction(double x, double y, std::string action) {
    double answer = 0;
    std::string Str;
    if (action == std::string("+")) {
        answer = x + y;
    }
    else if (action == std::string("-")) {
        answer = x - y;
    }
    else if (action == std::string("^")) {
        answer = pow(x,y);
    }
    else if (action == std::string("*")) {
        answer = x * y;
    }
    else if (action == std::string("/")) {
        answer = x / y;
    }
    Str = std::to_string(answer);
    if (answer < double(0)) {
        Str.insert(0, std::string("("));
        Str.append(std::string(")"));
    }
    return Str;
}


double calculate(std::vector<std::string> vect) {
    std::vector<std::string> vec = vect;
    if (std::size(vec) == 1) {
        return StringToDouble(vec[0]);
    }
    while (true) {
        std::vector<std::string>::iterator ind = std::find(vec.begin(), vec.end(), "^");
        if (ind == vec.end()) {
            ind = std::find(vec.begin(), vec.end(), "*");
            if (ind == vec.end()) {
                ind = std::find(vec.begin(), vec.end(), "/");
            }
        }
        int findIndex = ind - vec.begin();
        if (ind == vec.end()) {
            findIndex = 1;
       }
           
            std::string xString = vec[findIndex - 1];
            std::string yString = vec[findIndex + 1];
            std::string action = vec[findIndex];

          
            double xDouble = StringToDouble(xString);
            double yDouble = StringToDouble(yString);
         
                vec.erase(vec.begin() + findIndex);
                vec.erase(vec.begin() + findIndex);
                vec.erase(vec.begin() + findIndex - 1);
            
       
       /*for (auto& v : vec) {
                std::cout << v << " ";
           }*/
       //    std::cout <<  std::string(CalculateWithAction(xFloat, yFloat, action)) << std::endl;
       //    std::cout << xFloat << " " << yFloat << " " << action << std::endl;
           
           std::string answer = std::string(CalculateWithAction(xDouble, yDouble, action));

           if (vec.empty()) {
           if (answer.find("(") != std::string::npos) {
               answer = answer.substr(1);
               answer = answer.substr(0, answer.length() - 1);

           }
              return std::stod(answer);
           }
           vec.insert(vec.begin() + (findIndex - 1), answer);
        
        
    }
    return 0;
}

