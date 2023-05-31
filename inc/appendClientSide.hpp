/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   appendClientSide.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fech-cha <fech-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 20:06:16 by fech-cha          #+#    #+#             */
/*   Updated: 2023/05/31 03:50:21 by fech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef APPENDCIENTSIDE_HPP
# define APPENDCIENTSIDE_HPP

#include "/Users/fech-cha/Desktop/webserv/inc/pollingServ.hpp"


class appendClient
{
    private:
        int         _clientFd;
        std::string _header;
        std::string _body;
    public:
        appendClient();
        ~appendClient();
        
        
        // I/O methods for servers
        void    sendReq(int sockfd, const void *buf, int len, int flags);
        void    recvReq(int sockfd, void *buf, int len, int flags);

        //getters & setters
        int     getClientFd(void);
        void    setClientFd(int fd);

};

#endif