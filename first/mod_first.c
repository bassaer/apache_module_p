/* 
**  mod_first.c -- Apache sample first module
**  [Autogenerated via ``apxs -n first -g'']
**
**  To play with this sample module first compile it into a
**  DSO file and install it into Apache's modules directory 
**  by running:
**
**    $ apxs -c -i mod_first.c
**
**  Then activate it in Apache's httpd.conf file for instance
**  for the URL /first in as follows:
**
**    #   httpd.conf
**    LoadModule first_module modules/mod_first.so
**    <Location /first>
**    SetHandler first
**    </Location>
**
**  Then after restarting Apache via
**
**    $ apachectl restart
**
**  you immediately can request the URL /first and watch for the
**  output of this module. This can be achieved for instance via:
**
**    $ lynx -mime_header http://localhost/first 
**
**  The output should be similar to the following one:
**
**    HTTP/1.1 200 OK
**    Date: Tue, 31 Mar 1998 14:42:22 GMT
**    Server: Apache/1.3.4 (Unix)
**    Connection: close
**    Content-Type: text/html
**  
**    The sample page from mod_first.c
*/ 

#include "httpd.h"
#include "http_config.h"
#include "http_protocol.h"
#include "ap_config.h"

/* The sample content handler */
static int first_handler(request_rec *r)
{
    /*
    if (strcmp(r->handler, "first")) {
        return DECLINED;
    }
    */
    r->content_type = "text/html";      

    if (!r->header_only)
        ap_rputs("The sample page from mod_first.c\n", r);
    return OK;
}

static void first_register_hooks(apr_pool_t *p)
{
    ap_hook_handler(first_handler, NULL, NULL, APR_HOOK_MIDDLE);
}

/* Dispatch list for API hooks */
module AP_MODULE_DECLARE_DATA first_module = {
    STANDARD20_MODULE_STUFF, 
    NULL,                  /* create per-dir    config structures */
    NULL,                  /* merge  per-dir    config structures */
    NULL,                  /* create per-server config structures */
    NULL,                  /* merge  per-server config structures */
    NULL,                  /* table of config file commands       */
    first_register_hooks  /* register hooks                      */
};
