/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   webserv.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:56:03 by samajat           #+#    #+#             */
/*   Updated: 2023/03/21 13:03:12 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "requestParser.hpp"
#include "errorManager.hpp"

// std::string msg= "GET  /images HTTP/1.1\r\n"
//             "host: 192.241.213.46:6880\r\n"
//             "Upgrade-Insecure-Requests: 1\r\n"
//             "Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8\r\n"
//             "User-Agent: Mozilla/5.0 (Macintosh; Intel Mac OS X 10_12_3) AppleWebKit/602.4.8 (KHTML, like Gecko) Version/10.0.3 Safari/602.4.8\r\n"
//             "Accept-Language: en-us\r\n"
//             "Accept-Encoding: gzip, deflate\r\n"
//             "Connection: keep-alive\r\n\r\n";

std::string msg= "POST /images HTTP/1.1\r\n"
            "Host: example.com\r\n"
            "Content-Type: application/json\r\n"
            "Content-Length: 43\r\n\r\n"
            "{\"name\": \"John Doe\", \"email\": \"johndoe@example.com\"}";

//According to RFC "Each header field consists of a name followed by a colon (":") and the field value. Field names are case-insensitive. "
//So we need to convert all the keys to lower case
// std::string toLower(std::string str)
// {
//     std::transform(str.begin(), str.end(), str.begin(), ::tolower);
//     return str;
// }
int main ()
{
    clientRequestParser test(msg);
    std::string _uri ;

    // test.displayRequest();
    request_t _request = test.getRequest();
    std::cout << errorManager::isRequestValid(_request, _uri) << std::endl;
}