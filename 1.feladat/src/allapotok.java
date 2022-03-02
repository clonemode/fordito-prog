import static java.lang.Character.isDigit;
import static java.lang.Character.isLetter;

public class allapotok {
    static String input ;
    static int index ;
    allapotok(String s){
        input = s;
        index = 0;
    }
    void read(){
        index++;
    }
    void backup(){
        index--;
    }

    void allapot1()
    {
        if(index == input.length()-1)
            return;
        read();
        if(input.charAt(index) == ')' || input.charAt(index) == '}')
        {
            read();
        }
        if(isDigit(input.charAt(index))){           //Ha szám
            allapot4();
        }
        else if(isLetter(input.charAt(index))){     //Ha betű
            allapot2();
        }
        else{
            switch (input.charAt(index)){
                case'{':{
                    allapot6();
                    break;
                }
                case'}':{
                    allapot19();
                    break;
                }
                case'(':{
                    allapot8();
                    break;
                }
                case'*':{
                    allapot19();
                    break;
                }
                case')':{
                    allapot19();
                    break;
                }
                case':':{
                    allapot12();
                    break;
                }
                case'=':{
                    allapot19();
                    break;
                }
                case'<':{
                    allapot14();
                    break;
                }
                case'>':{
                    allapot17();
                    break;
                }
                case' ':{
                    allapot1();
                    break;
                }
                case'$':{
                    allapot21();
                    break;
                }
                default:allapot19();
            }
        }
    }
    void allapot2()
    {
        read();
        if(isDigit(input.charAt(index))){           //Ha szám
            allapot2();
        }
        else if(isLetter(input.charAt(index))){     //Ha betű
            allapot2();
        }
        else{
            allapot3();
        }
    }
    void allapot3()
    {
        backup();
        allapot1();
    }
    void allapot4()
    {
        read();
        if(isDigit(input.charAt(index))){           //Ha szám
            allapot5();
        }
        else if(isLetter(input.charAt(index))){     //Ha betű
            allapot4();
        }
        else
        {
            allapot5();
        }
    }
    void allapot5()
    {
        backup();
        allapot1();
    }
    void allapot6()
    {
        read();
        if(input.charAt(index) == '}'){
            allapot7();
        }
        else if (input.charAt(index) == '$'){
            allapot19();
        }
        else{
            allapot6();
        }
    }
    void allapot7()
    {
        allapot1();
    }

    void allapot8()
    {
        read();
        if(input.charAt(index) == '*'){
            allapot9();
        }
        else if (input.charAt(index) == '$'){
            allapot19();
        }
        else{
            allapot20();
        }

    }
    void allapot9()
    {
        read();
        if(input.charAt(index) == '*'){
            allapot10();
        }
        else if (input.charAt(index) == '$'){
            allapot19();
        }
        else{
            allapot9();
        }
    }
    void allapot10()
    {
        read();
        if(input.charAt(index) == '*'){
            allapot10();
        }
        else if(input.charAt(index) == ':'){
            allapot11();
        }
        else if (input.charAt(index) == '$'){
            allapot19();
        }
        else{
            allapot9();
        }
    }
    void allapot11()
    {
        allapot1();
    }
    void allapot12()
    {
        read();
        if(input.charAt(index) == '='){
            allapot13();
        }
        else if (input.charAt(index) == '$'){
            allapot19();
        }
        else{
            allapot20();
        }
    }
    void allapot13()
    {
        allapot1();
    }
    void allapot14()
    {
        read();
        if(input.charAt(index) == '='){
            allapot15();
        }
        else if(input.charAt(index) == '>'){
            allapot16();
        }
        else if (input.charAt(index) == '$'){
            allapot19();
        }
        else{
            allapot20();
        }
    }
    void allapot15()
    {
        allapot1();
    }
    void allapot16()
    {
        allapot1();
    }
    void allapot17()
    {
        read();
        if(input.charAt(index) == '='){
            allapot18();
        }
        else if (input.charAt(index) == '$'){
            allapot19();
        }
        else{
            allapot20();
        }
    }
    void allapot18()
    {
        allapot1();
    }
    void allapot19()
    {
        System.out.println("ERROR"+input.charAt(index));
        allapot1();
    }
    void allapot20()
    {
        backup();
        allapot1();
    }
    void allapot21()
    {
        System.out.println("Done");
        allapot1();
    }
}