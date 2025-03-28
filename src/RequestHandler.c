
#include "Parser.h"

#include <stdio.h>

char* processRequest(Token* request)
{
    printf("\nbegin processing request");

    char* method = request[0].method;
    char* response = malloc(4096);
    
    if(strcmp(method, "OPTIONS") == 0)
    {
        OPTIONSRequest(request, response);
    }
    if(strcmp(method, "GET") == 0)
    {
        GETRequest(request, response);
    }
    if(strcmp(method, "HEAD") == 0)
    {
        HEADRequest(request, response);
    }
    if(strcmp(method, "POST") == 0)
    {
        POSTRequest(request, response);
    }
    if(strcmp(method, "PUT") == 0)
    {
        PUTRequest(request, response);
    }
    if(strcmp(method, "DELETE") == 0)
    {
        DELETERequest(request, response);
    }
    if(strcmp(method, "TRACE") == 0)
    {
        TRACERequest(request, response);
    }
    if(strcmp(method, "CONNECT") == 0)
    {
        CONNECTRequest(request, response);
    }

    free(request);

    return response;
}

void OPTIONSRequest(char* request, char* response)
{

}

void GETRequest(char* request, char* response)
{

}

void HEADRequest(char* request, char* response)
{

}

void POSTRequest(char* request, char* response)
{

}

void PUTRequest(char* request, char* response)
{

}

void DELETERequest(char* request, char* response)
{

}

void TRACERequest(char* request, char* response)
{

}

void CONNECTRequest(char* request, char* response)
{

}

Token* findToken(Token* tokens, myTokenType identifier)
{
    Token* list = tokens;

    for(int i = 0; list[i].type != TOKEN_END; i++)
    {
        if(list[i].type == identifier)
        {
            return &(list[i]);
        }
    }

    return NULL;
}

Token* findHeaderToken(Token* tokens, char* identifier)
{
    Token* list = tokens;

    for(int i = 0; list[i].type != TOKEN_END; i++)
    {
        if(list[i].fieldName == identifier)
        {
            return &(list[i]);
        }
    }

    return NULL;
}