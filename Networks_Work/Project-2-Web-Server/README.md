CSCI 356 Fall 2024 Project 2 Starter Code
-----------------------------------------

This repository contains starter code for project 2, in which you will write a
pure-python dynamic web server. The main files are:

* `webserver.py` - Code for a mostly static, file-based, concurrent web server.

* `web_files` - A set of test html, css, image, and other files for the server.

Tasks:

- [x] implemented from scratch without HTTP-related python libraries or modules
- [x] opens "welcoming" socket and waits for connections from browsers  
- [x] concurrency via multithreading support: starts a separate thread for each connection
- [x] installed and tested on localhost, logos, or another machine
- [x] responds to "GET /hello" requests
  - [x] /hello page has html content and "text/html" mime-type
  - [x] links in /hello page are all clickable and work as intended
  - [x] /hello page content is dynamic, changing on each request
  - [x] /hello page content is interactive, using client (user) input in some way
     - [x] properly handles url escapes in client input
     - [x] reach goal: use cookies to retain previous user inputs
      - Correctly implemented all features described above and uses cookies for tracking how much times a user has visited a website
- [x] tracks basic statistics, like number of connections, errors, etc.
  - Can be found in the statistics page  
- [x] responds to "GET /status" requests with nicely-formatted statistics
- [x] responds to requests for contents of a file
- [x] support mime-types for file responses
    - [x] If path ends in ".html" or ".htm", mime-type will be "text/html"
    - [x] If path ends in ".jpg" or ".jpeg", mime-type will be "image/jpeg"
    - [x] If path ends in ".png", then mime-type will be "image/png"
    - [x] Supports ".txt", ".css", and ".js" path endings, with appropriate mime-types
      - Mime-types successfully supports html, css, js, txt, jpg, jpeg, png, etc 
- [x] obtain more complete and complex web site contents for testing
    - Grabbed holycross.edu to be used as a more complex website
- [x] default page support for directories and subdirectories: (NEED TO TALK TO WALSH ABOUT A COUPLE OF THINGS)
    - [x] respond to "GET /" requests with top-level index.html
    - [x] respond to "GET" requests ending with "/" with appropriate
      subdirectory index.html, if present
    - [x] reach goal: respond with index.html, if present, for any path to a
      directory, even if trailing "/" is not present 
    - [x] reach goal: if index.html is not present, instead respond with a
      "directory listing" of clickable links to each item in that directory
    - [x] use appropriate mime-type for index.html and directory listings
      - Correctly implemented the directory features, with "/" taking you to index.html, and demo and index_files directories prints all files and subdirectories  
- [x] reach goal: respond to "GET /whoami" with page showing info about the client
    - [x] show client's IP address and port number
    - [x] show client's browser "user-agent" string, taken from request headers
    - [x] show any cookies present in request headers
    - [x] show the user's privacy preferences, from DNT and/or Sec-GPC headers
      - Whoami successfully prints the IP, port, OS, language, sec-GPC, browser, cookies, user-agent, and cookies for how many time a user visted the wlecome.html  
- [x] reach goal: ban a browser, based on user-agent 
    - ** CURRENTLY BANS SAFARI **
- [x] reach goal: support HTTP cookies
    - [x] set a cookie with some contents, e.g. from input, or a visit counter
    - [x] use cookie in some responses, e.g. for /hello, /status, or /whoami
      -  Created a cookie object to be used to track hello request, and numVisited
- [ ] reach goal: support HTTP keep-alive feature, if requested by client
    - [ ] track and report statistics, including number of currently open
      connections, and average number of requests handled per connection
    - [ ] server initiates connection close eventually, e.g. after some number
      of requests, or after some amount of time has elapsed, or if connection
      remains idle for some amount of time.
- [x] project still does not use HTTP related python libraries or modules
- [x] includes basic error checking and does not crash under normal usage
  - Our code prints logs for tracking variables and used for error checking
- [x] prints trace of activity and status messages to console, for debugging
- [x] Rewrite README.md to describe final state of project, collaboration, etc.


Collaboration:
  - In terms of collaboration, we went to office hours two times to talk about an error in chrome regarding a socket, and how to get http-stay alive feature working
  - As well, we used chat-GPT a couple times for syntax with python. Examples included created functions for classes, and asked how to explain how headers, and cookies worked withtin a browser. 
