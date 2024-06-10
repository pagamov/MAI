using System;

namespace Olompia
{
    class MainClass
    {
        public static void Main(string[] args)
        {

            var nums = Console.ReadLine().Split(' ');

            float a;
            float b;
            float c;

            float z = 100;
            Console.WriteLine(z);


            float.TryParse(nums[0], out a);
            float.TryParse(nums[1], out b);
            float.TryParse(nums[2], out c);


            Console.WriteLine(a + b + c)
            //Console.WriteLine("{0:0.000000000}", (a + b) * c);
        }
    }
}
