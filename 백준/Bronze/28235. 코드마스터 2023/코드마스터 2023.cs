using System;

namespace MyCompiler {
    class Program {
        public static void Main(string[] args) {
            string input = Console.ReadLine();
            if(input.Equals("SONGDO")){
                Console.Write("HIGHSCHOOL");
            }
            else if(input.Equals("CODE")){
                Console.Write("MASTER");
            }
            else if(input.Equals("2023")){
                Console.Write("0611");
            }
            else{
                Console.Write("CONTEST");
            }
        }
    }
}
