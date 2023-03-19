/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorManager.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:49:48 by samajat           #+#    #+#             */
/*   Updated: 2023/03/19 11:12:03 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORMANAGER_HPP
# define ERRORMANAGER_HPP

#include "utils.hpp"


//All the functions in this class are static as We don't need to create an object of this class

class errorManager
{
    private:
    typedef   std::string    method_t;
    typedef   std::string    protocol_t;
    
    static const std::string    _validMethods[3];
    static const std::string    _validProtocol;

    public:
    static bool  isRequestValid(request_t request);
    

    
    private:
    static  bool        isMethodValid(method_t method);
    static  bool        isProtocolValid(protocol_t protocol);
    static  std::string        isURIValid(const std::string& uri);
    static  bool        isRestOfRequestValid(request_t request);
};


#endif