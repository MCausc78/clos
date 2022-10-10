using System;
using System.Collections.Generic;
using System.Text;
using System.Xml.Linq;

namespace Builder
{
    class Program
    {
        public static int Main()
        {
            Project p = new Project(XDocument.Load("q.xml"));
            Console.WriteLine(p.Build().ToString());
            return 0;
        }
    }
}
