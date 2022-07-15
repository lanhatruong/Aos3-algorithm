#include <algorithm>
#include <iostream>


int main(){

    int i = 0;
    int loopStr;
    int numberOfStr;
    int posOutputStrEnhance = 0;
    int inputStrLen;
    int startEqual;
    int stopEqual;
    std::string inputStr;
    std::cin >> numberOfStr;
    std::cin.ignore();
 
    for(loopStr = 0; loopStr < numberOfStr; loopStr++){
        std::cin >> inputStr;
        inputStrLen = inputStr.length();
        char* outStrEnhance = new char[2*inputStrLen + 1];

        for(i = 0; i < inputStrLen - 1 ;){
            // enhance this char to ouput
            if(inputStr[i] < inputStr[i+1]){
                outStrEnhance[posOutputStrEnhance++] = inputStr[i];
                outStrEnhance[posOutputStrEnhance++] = inputStr[i];
                i++;
            }
            else if( inputStr[i] ==  inputStr[i+1]){
                startEqual = i;
                while((i < inputStrLen - 1 )&& (inputStr[i] == inputStr[i+1])){
                    i++;
                }
                stopEqual = i;
                // stopEqual is last char of inputStr
                if(stopEqual == inputStrLen - 1){
                    for(int j = startEqual; j < stopEqual ; j++){
                        outStrEnhance[posOutputStrEnhance++] = inputStr[startEqual];
                    }
                    break;
                }
                // PEEL case i point to last E
                else{
                    if(inputStr[stopEqual] < inputStr[stopEqual+1]){
                        for(int j = startEqual; j <= stopEqual; j++){
                            outStrEnhance[posOutputStrEnhance++] = inputStr[startEqual];
                            outStrEnhance[posOutputStrEnhance++] = inputStr[startEqual];
                        }
                    }
                    else{
                        for(int j = startEqual; j <= stopEqual; j++){
                            outStrEnhance[posOutputStrEnhance++] = inputStr[startEqual];
                            
                        }

                    }
                }
                i++;
            }
            // just copy to ouput this char  
            else{
                outStrEnhance[posOutputStrEnhance++] = inputStr[i];
                i++;
            }
        }

        //copy last char of input str
        outStrEnhance[posOutputStrEnhance++] = inputStr[inputStrLen - 1];
        // null termanited
        outStrEnhance[posOutputStrEnhance] = 0;
        std::cout << "Case #" << loopStr+1 <<": " << outStrEnhance << std::endl;
        delete[] outStrEnhance;
        posOutputStrEnhance = 0;
    }
    return 0;     
}
 