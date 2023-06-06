/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   appendClientSide.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fech-cha <fech-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 20:06:16 by fech-cha          #+#    #+#             */
/*   Updated: 2023/06/06 18:15:50 by fech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef APPENDCLIENTSIDE_HPP
# define APPENDCLIENTSIDE_HPP

#include "pollingServ.hpp"
# define chunked 1
# define contentLength 2 
# define nobody 69
# define closeConnect 3
# define responseGo 1
# define lastChunk "0\r\n\r\n"
# define CRLF "\r\n\r\n"
# define endOfBody 69
# define endOfHeader 420

class appendClient
{ 
    private:
    
        //checking flags
        long        _contentLength;
        long        _bodySize;
        int         _checkHead;
        int         _checkBody;
        int         _bodyType;
        int         _responseStatus;
        int         _responseSent;
        
        //fd of the client
        int         _clientFd;
        
        std::string _tmp;
        std::string _header;
        std::string _body;
        std::string _httpRequest;
        std::string _httpRespond;
    public:
        appendClient();
        ~appendClient();
        
        
        // I/O methods for servers
        void    sendReq(int sockfd);
        void    recvHead();
        void    recvBody(std::string req);

        //getters & setters
        int     getClientFd(void);
        void    setClientFd(int fd);
        
        int     getHeadStatus();
        int     getBodyStatus();
        
        void    setHeadStatus(int head);
        void    setBodyStatus(int body);
        
        std::string getHeader();
        std::string getBody();

        void    setBody(std::string body);
        
        void                    parseChunked(std::string& chunkedData);
        void                    copyReq(char *req, int size);
        std::string::size_type  checkCRLForChunk(std::string test);
    
        void    getBodyType();
        void    getBodyRest();
        int     getResponseStat();
        void    setResponseStat(int stat);
        void    setHTTPRequest();
        void    getContentLength();
        std::string getHTTPResponse();

};

#endif