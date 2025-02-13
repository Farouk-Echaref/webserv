# WebServ_42

Using *`Object-Oriented Programming`* and the *`Finite State Machine`* design pattern, and with the power of *`SOLID Principles`*, I embarked on a *`C++`* journey with *`Webserv`*.

In collaboration with my team, we crafted a high-performance web server that boasts several key features. 

These include a *`Configuration File`* with its unique syntax, drawing inspiration from Nginx, *`non-blocking behavior`* achieved through *`I/O Multiplexing`*, support for *`multiple ports`*, precise *`HTTP response`* handling, and a range of captivating functionalities such as *`Uploading Files`* with large sizes to the server, *`Cookies Management`*, *`Sessions`*, and *`CGI`* support (with compatibility for *`Python`* and *`Perl`*). 

It is a web server that is compliant with the HTTP Protocol, and conditionally compliant with the RFC manual. 

My journey stands as a testament to my unwavering commitment to excellence and innovation, demonstrating my ability to harness the power of C++ to create a remarkable digital asset.

![web-servers](https://github.com/Farouk-Echaref/webserv/assets/66710845/fc379cc0-0ceb-4eb4-bd0c-eb5c93d191a3)

## Table of Contents

- [Features](#features)
- [Getting Started](#getting-started)
  - [Project Architecture](#project-architecture)
  - [Installation](#installation)
- [Configuration](#configuration)
- [Resources](#resources)

## Features

- **WebSockets:** WebServ supports WebSockets, enabling real-time, bidirectional communication between clients and the server.

- **I/O Multiplexing:** Utilizing the select mechanism, WebServ efficiently manages multiple connections, making it suitable for handling high loads.

- **HTTP Methods:** WebServ handles common HTTP methods such as POST, GET, and DELETE, allowing you to build dynamic web applications.

- **Design Patterns:** The project built on the Finite State Machine design pattern and follows SOLID principles and employs the Singleton design pattern, ensuring clean, maintainable code.

- **Data Mapping:** The entire project is mapped, simplifying data manipulation and enhancing code readability and efficiency.

## Getting Started

### Project Architecture

#### Socket-Bind-listing-connection
![S_B_L_C](assets/connection.png)
#### Socket:
Sockets allow communication between two different processes on the same or different machines.
![Socket](assets/socket.png)

#### Bind

bind is a system call that associates a socket with a local address and port number. This allows the socket to receive connections from other computers on the network.

![Bind](assets/bind.png)

#### listen
is used to listen for incoming connections on a socket. The listen() function takes two arguments: the first argument is the socket file descriptor, and the second argument is the backlog queue size.
The backlog queue size is the maximum number of connections that can be queued before the system starts refusing connections.

#### accept

is used to accept an incoming connection on a socket. The accept() function takes two arguments: the first argument is the socket file descriptor, and the second argument is a pointer to a sockaddr structure, which will be filled in with the address of the client that connected.

---
#### HTTP 

HTTP stands for HyperText Transfer Protocol. It is a set of rules for exchanging data between a client and a server. HTTP is the foundation of the World Wide Web, and it is used to transfer all kinds of data, including HTML pages, images, videos, and files.
Here explain all of the previews :
![HTTP](assets/HTTP.png)

#### Request:
![Request](assets/request.png)
##### RequestLine :
![requestLine](assets/requestLine.png)


****
#### CGI :
- **CGI** : (Common Gateway Interface) is used to provide a dynamic content to the user. It is a standard way for web servers to interact with external programs. CGI programs are typically written in scripting languages such as Perl, Python, or PHP.

When a user requests a page that contains a CGI script, the web server will execute the script and return the results to the user. This allows web servers to generate dynamic content, such as personalized web pages or interactive forms.

![cgi](assets/cgi2.png)

Here explain more about CGI how it's Work

![Cgi](assets/Cgi.png)

****

### Installation

- To install WebServ, follow these steps:

   ```sh
     https://github.com/Farouk-Echaref/webserv
     cd webServ
     make
   ```
- run the webserver
  ```
    ./webserv /path/to/config.conf
  ```


## Configuration

WebServ is highly configurable, allowing you to use a custom configuration file. To specify a custom configuration file, create a .conf configuration file (e.g., `my_config.conf`) with the desired settings:

```conf
#Upload Server
server {
	listen 6969 7000;
	server_name 127.0.0.1;
	upload ./www/upload;
	cgi ./www/cgi_files;
	location / {
		autoindex on;
        
		root ./www/upload;
		index upload.html;
	}
	location /cgi_files {
		root ./www/cgi_files;
	}
	
	allow GET POST;

	# max_body_size 0;
	autoindex on;
	# return 302 https://www.youtube.com/;
}


#Main Server
server {
	listen 5000 9999;
	server_name 127.0.0.1;
	cgi ./www/cgi_files;

	location / {
		autoindex on;
        
		root ./www/cgi;
		index cgi.html;
	}

	location /cgi_files {
		root ./www/cgi_files;
	}
	
	allow GET POST ;
	# max_body_size 8;
	# autoindex on;
	# return 302 https://www.youtube.com/;
	# location /404.html {
	# 	root /var/www/html/;
	# }
}

#Delete server
server {
	listen 9000;
	server_name 127.0.0.1;

	allow DELETE;
	location / {
		root ./www/random;
		index page.html;
	}

}

#Main Server
server {
	listen 8001;
	server_name 127.0.0.1;
	root ./www;
	location / {
		autoindex on;
        
		root ./www/cgi;
		index index.html;
	}
	location /images {
		autoindex on;
		root ./www/images;

		# index index.html;
	}
	location /cgi_bin {
        root ./www/html/cgi_bin;
        allow GET POST;
        index hello.html;
        path_info .py /usr/bin/python3;
        path_info .php ./php-cgi;
    }
	allow POST GET;
	# max_body_size 8;
	# autoindex on;
	# return 302 https://www.youtube.com/;
	location /404.html {
		root /var/www/html/;
	}
}
```

## Resources

* https://beej.us/guide/bgnet/html/split/system-calls-or-bust.html
* https://web.archive.org/web/20100127161358/http://hoohoo.ncsa.illinois.edu/cgi/
* https://www.rfc-editor.org/rfc/rfc6265
* https://www.youtube.com/playlist?list=PLZIwlOSv75K7jXcVABdIo3wyKp5NwXKlW
* https://www.youtube.com/watch?v=wB9tIg209-8
