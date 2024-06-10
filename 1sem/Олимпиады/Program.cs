using System;

namespace Olompia
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            var z = Console.ReadLine();

            var nums = Console.ReadLine().Split(' ');

            int a;
            int b;
            int c;

            Int32.TryParse(nums[0], out a);
            Int32.TryParse(nums[1], out b);
            Int32.TryParse(z, out c);

            double u = Math.Sqrt(Math.Pow(a, 2) + Math.Pow(b, 2));
            int y = (int)u;

            if (y < c){
                Console.WriteLine("YES");
            }
            else{
                Console.WriteLine("NO");
            }
            //Console.WriteLine("{0:0.000000000000000}", ((a + b) * c));
             {
            }
        }
    }
}
