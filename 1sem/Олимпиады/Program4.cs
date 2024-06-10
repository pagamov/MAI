using System;

namespace Olompia
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            var nums = Console.ReadLine().Split(' ');

            double a;
            double b;
            double c;

            Double.TryParse(nums[0], out a);
            Double.TryParse(nums[1], out b);
            Double.TryParse(nums[2], out c);


            var mums = Console.ReadLine().Split(' ');

            double aa;
            double bb;
            double cc;

            Double.TryParse(mums[0], out aa);
            Double.TryParse(mums[1], out bb);
            Double.TryParse(mums[2], out cc);


            if (Math.Sqrt((aa - a) * (aa - a) + (bb - b) * (bb - b)) <= (cc + c))
            {
                Console.WriteLine("YES");
            }
            else
            {
                Console.WriteLine("NO");
			}

        }
    }
}