\ProvidesClass{xcumcmart}[2019/04/18, He Changhong, Ver.1.00.00]

\LoadClass[cs4size,oneside,UTF8]{ctexart}
\usepackage{array}
  
%%%%geometry
\RequirePackage{geometry}
\geometry{left = 2.5cm, right = 2.5cm, top = 2.5cm, bottom = 2.5cm}

\RequirePackage{makecell}
\RequirePackage{graphicx}
\def\maketitle{
  % \centerline{\rule{16cm}{0.15em}}
  % \thispagestyle{empty}  %首页不编号
  \setcounter{page}{1} %page编号从1开始
  \begin{center}
    {\heiti\zihao{3} \@title \par}%
    \vspace{2\ccwd}
    {\kaishu \zihao{4} \@author \par}
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


%%%%% 表格宽度，高度精确设置
\newcommand{\PreserveBackslash}[1]{\let\temp=\\#1\let\\=\temp}
\newcolumntype{C}[1]{>{\PreserveBackslash\centering}p{#1}}
\newcolumntype{R}[1]{>{\PreserveBackslash\raggedleft}p{#1}}
\newcolumntype{L}[1]{>{\PreserveBackslash\raggedright}p{#1}}

\newenvironment{cnabstract}{%\pushziti%
    \begin{center}{\zihao{4}\heiti \cnabstractname}\end{center}\vspace{1\ccwd}
    \songti\zihao{-4}
    \@afterheading}
    {\par\newpage}

%%%%Head and Foot
\RequirePackage{fancyhdr}
\pagestyle{fancy}
\lhead{\zihao{6} \@title}\chead{}\rhead{\zihao{6} \@author}
\lfoot{}\cfoot{\thepage}\rfoot{}
\renewcommand{\headrulewidth}{0pt} 

%%%%Sections
\CTEXsetup[format = {\zihao{4}\bfseries\centering}]{section}
\CTEXsetup[format = {\zihao{-4}\bfseries}]{subsection}
\CTEXsetup[format = {\zihao{-4}\bfseries}]{subsubsection}
\CTEXsetup[format=  {\Large\bfseries}]{section} %章节标题左对齐
\linespread{1.0}


%----------------------- Theorems -----------------------------------
\newtheorem{theorem}{{定理}}
\newtheorem{proposition}{{命题}}
\newtheorem{lemma}{{引理}}
\newtheorem{corollary}{{推论}}[theorem]
\newtheorem{definition}{{定义}}
\newtheorem{example}{{例}}

%\endlinechar `\^^M
\endinput
