using System.Collections.Generic;
using System.IO;
using System.Text;
using System.Linq;
using System.Xml.Linq;
using Builder;
using System;

namespace Builder
{
    class Project
    {
        private string compiler;
        public string Compiler
        { get {
                return compiler;
            } set {
                compiler = value;
            }
        }
        private string root;
        public string Root
        {
            get
            {
                return root;
            }
            set
            {
                root = value;
            }
        }
        private readonly XElement proj;
        public Project(string compiler)
        {
            this.Compiler = compiler;
            this.Root = ".";
        }
        public Project(string compiler, string root)
        {
            this.Compiler = compiler;
            this.Root = root;
        }

        public Project(XDocument xdoc)
        {
            proj = xdoc.Element("project");
            this.Root = proj.Element("root").Value;
            this.Compiler = proj.Element("compiler").Value;
        }
        public StringBuilder Build()
        {
            StringBuilder sb = new StringBuilder();
            string[] fs = GetFiles(root);
            string joining = proj.Element("options").Element("joining").Value;
            string ds = String.Join(joining, GetDirectories(Root));
            sb.AppendLine(this.proj.Element("start").Value);

            foreach(string f in fs)
                if(f.EndsWith(".c"))
                    sb.AppendLine(compiler.Replace("$DIRECTORIES$", ds).Replace("$FILE$", f.Replace("\\", "/").Substring(0, f.LastIndexOf('.'))).Replace(Root, ""));
            sb.AppendLine(this.proj.Element("end").Value);
            return sb;
        }
        public string[] GetFiles(string directory)
        {
            List<string> ls = new List<string>();
            string[] ds = Directory.GetDirectories(directory);
            if (ds.Length > 0)
            {
                foreach (string d in ds)
                {
                    ls.AddRange(GetFiles(d).AsEnumerable());
                }
            }
            string[] fs = Directory.GetFiles(directory);
            foreach(string f in fs)
            {
                ls.Add(f);
            }
            return ls.ToArray();
        }
        public string[] GetDirectories(string directory)
        {
            List<string> ls = new List<string>();
            string[] ds = Directory.GetDirectories(directory);
            if (ds.Length > 0)
            {
                foreach (string d in ds)
                    ls.AddRange(GetDirectories(d).AsEnumerable());
            }
            string starting = proj.Element("options").Element("directories").Element("every-start").Value;
            string ending = proj.Element("options").Element("directories").Element("every-end").Value;
            return ls.Select(e => starting + e + ending).ToArray();
        }
    }
}
