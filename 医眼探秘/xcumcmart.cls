\ProvidesClass{xcumcmart}[2013/08/25, Ch'en Meng, Ver.1.00.00]

\LoadClass[cs4size,oneside,UTF8]{ctexart}
\usepackage{array}
  
%%%%geometry
\RequirePackage{geometry}
\geometry{left = 2.5cm, right = 2.5cm, top = 2.5cm, bottom = 2.5cm}

%%%%declaration page
\newtoks\displaytitle
\newtoks\school
\newtoks\authorone
\newtoks\authortwo
\newtoks\authorthree
\newtoks\advisor

\RequirePackage{makecell}
\RequirePackage{graphicx}
\def\maketitle{%
    % \centerline{\rule{16cm}{0.15em}}
  % \null
  %头版页
{\thispagestyle{empty}\par\songti\zihao{2}\centering\null 
《医眼探秘》课程报告\\\null\null
\zihao{4}
\par 学生姓名：\uline{何长鸿　　　　　}\\\null
\par 学生学号：\uline{2016141482154　}\\\null
\par 学　　院：\uline{计算机学院　　　}\\\null
\par 专　　业：\uline{计算机科学与技术}\\\null
\vspace{5cm}
\par 提交报告时间：2019年5月21日
\newpage

}
  % \thispagestyle{empty}
  \setcounter{page}{1}
  \null
  \begin{center}
     {\heiti\zihao{-2} \@title \par}%
     \vspace{1\ccwd}
     {\kaishu\zihao{-4} \@author}
  \end{center}
  % \vspace{2\ccwd}
  }

%%%%Abstract & Keywords
\newcommand\cnabstractname{\ziju{2}摘要}
\newcommand\enabstractname{ABSTRACT}
\newcommand\cnkeywords[1]{\pushziti {\heiti\zihao{-4}\cnkeywordsname #1}}

\newcommand\cnkeywordsname{关键词}
\newcommand\enkeywords[1]{\pushziti {\bfseries\zihao{-4}\enkeywordsname #1}}
\newcommand\enkeywordsname{Key words}
  


\newcommand{\PreserveBackslash}[1]{\let\temp=\\#1\let\\=\temp}
\newcolumntype{C}[1]{>{\PreserveBackslash\centering}p{#1}}
\newcolumntype{R}[1]{>{\PreserveBackslash\raggedleft}p{#1}}
\newcolumntype{L}[1]{>{\PreserveBackslash\raggedright}p{#1}}

\newenvironment{cnabstract}{%\pushziti%
    \begin{center}{\zihao{4}\heiti \cnabstractname}\end{center}\vspace{1\ccwd}
    \songti\zihao{-4} %正文字号
    \@afterheading}
    {\par\newpage}

%%%%Head and Foot
\RequirePackage{fancyhdr}
\pagestyle{fancy}
\lhead{\songti\zihao{-5}课程名称：医眼探秘}\chead{\songti\zihao{-5}学生姓名：何长鸿}\rhead{\songti\zihao{-5}学生学号：2016141482154}
\lfoot{}\cfoot{\thepage}\rfoot{}
\renewcommand{\headrulewidth}{0pt} 

%%%%Sections
\CTEXsetup[format = {\zihao{4}\bfseries\centering}]{section}
\CTEXsetup[format = {\zihao{-4}\bfseries}]{subsection}
\CTEXsetup[format = {\zihao{-4}\bfseries}]{subsubsection}
\linespread{1.0}
%------------------------ sections -------------------------
%\renewcommand\section{\@startsection
%            {section}{2}{\z@}%   {name}{depth}{}
%                {3.5ex \@plus 1ex \@minus .2ex}% positive->leave parindent
%                {2.3ex \@plus.2ex}%
%                {\reset@font\fontsize{13.75pt}{\baselineskip}\sectionformat}}
%\renewcommand\sectionname{\arabic{section}}
%\renewcommand\sectionformat{\selectfont\bfseries}

%----------------------- Theorems -----------------------------------
\newtheorem{theorem}{{定理}}
\newtheorem{proposition}{{命题}}
\newtheorem{lemma}{{引理}}
\newtheorem{corollary}{{推论}}[theorem]
\newtheorem{definition}{{定义}}
\newtheorem{example}{{例}}

%\endlinechar `\^^M
\endinput
