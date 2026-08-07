# Mini Search Engine 🗂️

## About
    The project itself is a search engine, obviously
    a very basic one but it has been thought 
    to be a practice and a way to learn.

    The project started in September 2025 at
    the start of my last year of High School
    because I wanted to do more than a regular
    HS student so I started reading books
    about code and related topics and work 
    on projects like this.

    Check Updates to know what has been done
    and what will be done soon.

## Goals 🎯
    - Learn About Algorithms
    - Learn About Data Structures
    - Learn how to tokenize 
    - Learn how ranking works 
    - Learn how to work with git with the aim to be able to help and give 
    contributions in open source projects
    - Learn how to write tests using "Google Test".

    


## Project Structure 📁
    -mini-search-engine
        -src/
            - All the source files
            -CMakeLists.txt
        -tests
            -Tests File
            -CMakeLists.txt
        -data
        -build (ignored)
        .gitignore
        CMakeLists.txt
        README.md

# Useful info
    The project uses the [ICU (International Components for Unicode)]
    (https://icu.unicode.org/) library to handle strings.
    ICU is distributed under the [ICU License](https://github.com/unicode-org/icu/blob/main/LICENSE),
    a permissive open source license.

    
## Benchmark Dataset
    Performance tests were conducted on a M2 MacBook using the **Large Movie Review Dataset (aclImdb)** introduced by:

    > Andrew L. Maas, Raymond E. Daly, Peter T. Pham, Dan Huang, Andrew Y. Ng, Christopher Potts.
    > Learning Word Vectors for Sentiment Analysis.
    > Proceedings of the 49th Annual Meeting of the Association for Computational Linguistics (ACL-HLT), 2011.

    @InProceedings{maas-EtAl:2011:ACL-HLT2011,
    author    = {Maas, Andrew L. and Daly, Raymond E. and Pham, Peter T.
                and Huang, Dan and Ng, Andrew Y. and Potts, Christopher},
    title     = {Learning Word Vectors for Sentiment Analysis},
    booktitle = {Proceedings of the 49th Annual Meeting of the Association for Computational Linguistics: Human Language Technologies},
    year      = {2011},
    pages     = {142--150}
    }

    The dataset contains **50,000 movie reviews** for binary sentiment classification. It is used in this project exclusively for indexing and search performance evaluation.
    
    Benchmark Results (12500 docs):
        Indexing:
            - ~1.13 seconds
            - ~11028 docs/second
            - ~90.6 μs average per-document indexing latency
        Searching (3 word query):
            - ~1.78 seconds
            - ~56.2 query/second
# Status
    The project is now resumed (current date: December 2025).
    The main goal of implementing indexing, 
    tokenization and tf-idf search has been reached.
    Although the goal has been achieved, the project
    is now active again with the aim of making it better
    and of publishing it via Github Releases 
    for MacOs platform.
    
## Enjoy The Ride 🚀🚀