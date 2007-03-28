/*   $OSSEC, os_regex_internal.h, v0.3, 2005/04/05, Daniel B. Cid$   */

/* Copyright (C) 2003,2004,2005 Daniel B. Cid <dcid@ossec.net>
 * All right reserved.
 *
 * This program is a free software; you can redistribute it
 * and/or modify it under the terms of the GNU General Public
 * License (version 2) as published by the FSF - Free Software
 * Foundation.
 */


#ifndef __OS_INTERNAL_H
#define __OS_INTERNAL_H


/*
 * Defining some caracters to be used.
*/
#define BACKSLASH   '\\'
#define ENDSTR      '\0'
#define ENDLINE     '\n'
#define BEGINREGEX  '^'
#define ENDREGEX    '$'
#define OR          '|'
#define AND         '&'

#define TRUE         1 
#define FALSE        0


/* Pattern flags */
#define BEGIN_SET   0000200
#define END_SET     0000400     


/* uchar */
typedef unsigned char uchar;


/* _IsD Returns 1 if it is a number */
#define _IsD(x) ((x >= 48) && (x <= 57))


/* Is it a character ?
 * a-z or A-Z or 0-9
 * Returns 1 if true
 */
#define _IsW(x) ((x >= 48 && x <= 57 )|| \
		         (x >= 65 && x <= 90 )|| \
		         (x >= 97 && x <= 122)) 


/* Is it a ' ' (blank)
 * Ascii 32
 * Returns 1 if true
 */
#define _IsS(x)	(x == 32)


/* Check for parenthesis */
#define prts(x) (x == '(')


/* Is it '+' or '*'
 * Returns 1 on success
 */
#define isPlus(x)    ((x == '+') || (x == '*'))


/* True char */
#define TRUECHAR    1


/* Is "y" a valid "x"?.
 * Returns 1 on success
 */
#define Regex(x,y)   (regexmap[x][y] == TRUECHAR)
#define Regex2(x,y)   (x == 'd' && y >= 48 && y <= 57)|| \
                     (x == 's' && y == 32)|| \
                     ((x == 'p') && \
                      ((y >= 40 && y <= 46)|| \
                      (y >= 58 && y <= 63)))|| \
                     ((x == 'w') && \
                      ((y == '_')|| \
                      (y >= 48 && y <= 57)|| \
                      (y >= 65 && y <= 90)|| \
                      (y >= 97 && y <= 122)))|| \
                     (x == '.')|| \
                     ((x == '\\') && (y == '\\'))|| \
                     ((x == 'n') && (y == '\n'))|| \
                     (x == 'S' && y != 32)|| \
                     (x == 'D' && (y < 48 || y > 57))|| \
                     (x == 'W' && (y < 48 || y > 122 || \
                     (y > 57 && y <65)||(y > 90 && y< 97)))


/* Charmap for case insensitive search */
static const uchar charmap[] = {
        '\000', '\001', '\002', '\003', '\004', '\005', '\006', '\007',
        '\010', '\011', '\012', '\013', '\014', '\015', '\016', '\017',
        '\020', '\021', '\022', '\023', '\024', '\025', '\026', '\027',
        '\030', '\031', '\032', '\033', '\034', '\035', '\036', '\037',
        '\040', '\041', '\042', '\043', '\044', '\045', '\046', '\047',
        '\050', '\051', '\052', '\053', '\054', '\055', '\056', '\057',
        '\060', '\061', '\062', '\063', '\064', '\065', '\066', '\067',
        '\070', '\071', '\072', '\073', '\074', '\075', '\076', '\077',
        '\100', '\141', '\142', '\143', '\144', '\145', '\146', '\147',
        '\150', '\151', '\152', '\153', '\154', '\155', '\156', '\157',
        '\160', '\161', '\162', '\163', '\164', '\165', '\166', '\167',
        '\170', '\171', '\172', '\133', '\134', '\135', '\136', '\137',
        '\140', '\141', '\142', '\143', '\144', '\145', '\146', '\147',
        '\150', '\151', '\152', '\153', '\154', '\155', '\156', '\157',
        '\160', '\161', '\162', '\163', '\164', '\165', '\166', '\167',
        '\170', '\171', '\172', '\173', '\174', '\175', '\176', '\177',
        '\200', '\201', '\202', '\203', '\204', '\205', '\206', '\207',
        '\210', '\211', '\212', '\213', '\214', '\215', '\216', '\217',
        '\220', '\221', '\222', '\223', '\224', '\225', '\226', '\227',
        '\230', '\231', '\232', '\233', '\234', '\235', '\236', '\237',
        '\240', '\241', '\242', '\243', '\244', '\245', '\246', '\247',
        '\250', '\251', '\252', '\253', '\254', '\255', '\256', '\257',
        '\260', '\261', '\262', '\263', '\264', '\265', '\266', '\267',
        '\270', '\271', '\272', '\273', '\274', '\275', '\276', '\277',
        '\300', '\301', '\302', '\303', '\304', '\305', '\306', '\307',
        '\310', '\311', '\312', '\313', '\314', '\315', '\316', '\317',
        '\320', '\321', '\322', '\323', '\324', '\325', '\326', '\327',
        '\330', '\331', '\332', '\333', '\334', '\335', '\336', '\337',
        '\340', '\341', '\342', '\343', '\344', '\345', '\346', '\347',
        '\350', '\351', '\352', '\353', '\354', '\355', '\356', '\357',
        '\360', '\361', '\362', '\363', '\364', '\365', '\366', '\367',
        '\370', '\371', '\372', '\373', '\374', '\375', '\376', '\377',
    };



/* Regex mapping 
 * 0  = none
 * 1  = \d
 * 2  = \w
 * 3  = \s
 * 4  = \p
 * 5  = \( 
 * 6  = \)
 * 7  = \\
 * 8  = \D
 * 9  = \W
 * 10 = \S
 * 11 = \. 
 * 12 = \t
 * 13 = \$
 * 14 = |
 */
static const uchar regexmap[][256] = 
{
    {},
    {
        '\000', '\000', '\000', '\000', '\000', '\000', '\000', '\000',
        '\000', '\000', '\000', '\000', '\000', '\000', '\000', '\000',
        '\000', '\000', '\000', '\000', '\000', '\000', '\000', '\000',
        '\000', '\000', '\000', '\000', '\000', '\000', '\000', '\000',
        '\000', '\000', '\000', '\000', '\000', '\000', '\000', '\000',
        '\000', '\000', '\000', '\000', '\000', '\000', '\000', '\000',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\000', '\073', '\074', '\075', '\076', '\077',
        '\100', '\141', '\142', '\143', '\144', '\145', '\146', '\147',
        '\150', '\151', '\152', '\153', '\154', '\155', '\156', '\157',
        '\160', '\161', '\162', '\163', '\164', '\165', '\166', '\167',
        '\170', '\171', '\172', '\133', '\134', '\135', '\136', '\137',
        '\140', '\141', '\142', '\143', '\144', '\145', '\146', '\147',
        '\150', '\151', '\152', '\153', '\154', '\155', '\156', '\157',
        '\160', '\161', '\162', '\163', '\164', '\165', '\166', '\167',
        '\170', '\171', '\172', '\173', '\174', '\175', '\176', '\177',
        '\200', '\201', '\202', '\203', '\204', '\205', '\206', '\207',
        '\210', '\211', '\212', '\213', '\214', '\215', '\216', '\217',
        '\220', '\221', '\222', '\223', '\224', '\225', '\226', '\227',
        '\230', '\231', '\232', '\233', '\234', '\235', '\236', '\237',
        '\240', '\241', '\242', '\243', '\244', '\245', '\246', '\247',
        '\250', '\251', '\252', '\253', '\254', '\255', '\256', '\257',
        '\260', '\261', '\262', '\263', '\264', '\265', '\266', '\267',
        '\270', '\271', '\272', '\273', '\274', '\275', '\276', '\277',
        '\300', '\301', '\302', '\303', '\304', '\305', '\306', '\307',
        '\310', '\311', '\312', '\313', '\314', '\315', '\316', '\317',
        '\320', '\321', '\322', '\323', '\324', '\325', '\326', '\327',
        '\330', '\331', '\332', '\333', '\334', '\335', '\336', '\337',
        '\340', '\341', '\342', '\343', '\344', '\345', '\346', '\347',
        '\350', '\351', '\352', '\353', '\354', '\355', '\356', '\357',
        '\360', '\361', '\362', '\363', '\364', '\365', '\366', '\367',
        '\370', '\371', '\372', '\373', '\374', '\375', '\376', '\377',
    },
    {
        '\000', '\000', '\002', '\003', '\004', '\005', '\006', '\007',
        '\010', '\011', '\012', '\013', '\014', '\015', '\016', '\017',
        '\020', '\021', '\022', '\023', '\024', '\025', '\026', '\027',
        '\030', '\031', '\032', '\033', '\034', '\035', '\036', '\037',
        '\040', '\041', '\042', '\043', '\044', '\045', '\046', '\047',
        '\050', '\051', '\052', '\053', '\054', '\001', '\056', '\057',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\072', '\073', '\074', '\075', '\076', '\077',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\133', '\134', '\135', '\136', '\001',
        '\140', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\173', '\174', '\175', '\176', '\177',
        '\200', '\201', '\202', '\203', '\204', '\205', '\206', '\207',
        '\210', '\211', '\212', '\213', '\214', '\215', '\216', '\217',
        '\220', '\221', '\222', '\223', '\224', '\225', '\226', '\227',
        '\230', '\231', '\232', '\233', '\234', '\235', '\236', '\237',
        '\240', '\241', '\242', '\243', '\244', '\245', '\246', '\247',
        '\250', '\251', '\252', '\253', '\254', '\255', '\256', '\257',
        '\260', '\261', '\262', '\263', '\264', '\265', '\266', '\267',
        '\270', '\271', '\272', '\273', '\274', '\275', '\276', '\277',
        '\300', '\301', '\302', '\303', '\304', '\305', '\306', '\307',
        '\310', '\311', '\312', '\313', '\314', '\315', '\316', '\317',
        '\320', '\321', '\322', '\323', '\324', '\325', '\326', '\327',
        '\330', '\331', '\332', '\333', '\334', '\335', '\336', '\337',
        '\340', '\341', '\342', '\343', '\344', '\345', '\346', '\347',
        '\350', '\351', '\352', '\353', '\354', '\355', '\356', '\357',
        '\360', '\361', '\362', '\363', '\364', '\365', '\366', '\367',    
        '\360', '\361', '\362', '\363', '\364', '\365', '\366', '\367',    
    },
    {
        '\000', '\000', '\002', '\003', '\004', '\005', '\006', '\007',
        '\010', '\011', '\012', '\013', '\014', '\015', '\016', '\017',
        '\020', '\021', '\022', '\023', '\024', '\025', '\026', '\027',
        '\030', '\031', '\032', '\033', '\034', '\035', '\036', '\037',
        '\001', '\041', '\042', '\043', '\044', '\045', '\046', '\047',
        '\050', '\051', '\052', '\053', '\054', '\055', '\056', '\057',
        '\060', '\061', '\062', '\063', '\064', '\065', '\066', '\067',
        '\070', '\071', '\072', '\073', '\074', '\075', '\076', '\077',
        '\100', '\141', '\142', '\143', '\144', '\145', '\146', '\147',
        '\150', '\151', '\152', '\153', '\154', '\155', '\156', '\157',
        '\160', '\161', '\162', '\163', '\164', '\165', '\166', '\167',
        '\170', '\171', '\172', '\133', '\134', '\135', '\136', '\137',
        '\140', '\141', '\142', '\143', '\144', '\145', '\146', '\147',
        '\150', '\151', '\152', '\153', '\154', '\155', '\156', '\157',
        '\160', '\161', '\162', '\163', '\164', '\165', '\166', '\167',
        '\170', '\171', '\172', '\173', '\174', '\175', '\176', '\177',
        '\200', '\201', '\202', '\203', '\204', '\205', '\206', '\207',
        '\210', '\211', '\212', '\213', '\214', '\215', '\216', '\217',
        '\220', '\221', '\222', '\223', '\224', '\225', '\226', '\227',
        '\230', '\231', '\232', '\233', '\234', '\235', '\236', '\237',
        '\240', '\241', '\242', '\243', '\244', '\245', '\246', '\247',
        '\250', '\251', '\252', '\253', '\254', '\255', '\256', '\257',
        '\260', '\261', '\262', '\263', '\264', '\265', '\266', '\267',
        '\270', '\271', '\272', '\273', '\274', '\275', '\276', '\277',
        '\300', '\301', '\302', '\303', '\304', '\305', '\306', '\307',
        '\310', '\311', '\312', '\313', '\314', '\315', '\316', '\317',
        '\320', '\321', '\322', '\323', '\324', '\325', '\326', '\327',
        '\330', '\331', '\332', '\333', '\334', '\335', '\336', '\337',
        '\340', '\341', '\342', '\343', '\344', '\345', '\346', '\347',
        '\350', '\351', '\352', '\353', '\354', '\355', '\356', '\357',
        '\360', '\361', '\362', '\363', '\364', '\365', '\366', '\367',
        '\370', '\371', '\372', '\373', '\374', '\375', '\376', '\377',
    },
    {
        '\000', '\000', '\002', '\003', '\004', '\005', '\006', '\007',
        '\010', '\011', '\012', '\013', '\014', '\015', '\016', '\017',
        '\020', '\021', '\022', '\023', '\024', '\025', '\026', '\027',
        '\030', '\031', '\032', '\033', '\034', '\035', '\036', '\037',
        '\040', '\041', '\042', '\043', '\044', '\045', '\046', '\047',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\057',
        '\060', '\061', '\062', '\063', '\064', '\065', '\066', '\067',
        '\070', '\071', '\001', '\001', '\001', '\001', '\001', '\001',
        '\100', '\141', '\142', '\143', '\144', '\145', '\146', '\147',
        '\150', '\151', '\152', '\153', '\154', '\155', '\156', '\157',
        '\160', '\161', '\162', '\163', '\164', '\165', '\166', '\167',
        '\170', '\171', '\172', '\001', '\000', '\001', '\136', '\137',
        '\140', '\141', '\142', '\143', '\144', '\145', '\146', '\147',
        '\150', '\151', '\152', '\153', '\154', '\155', '\156', '\157',
        '\160', '\161', '\162', '\163', '\164', '\165', '\166', '\167',
        '\170', '\171', '\172', '\173', '\174', '\175', '\176', '\177',
        '\200', '\201', '\202', '\203', '\204', '\205', '\206', '\207',
        '\210', '\211', '\212', '\213', '\214', '\215', '\216', '\217',
        '\220', '\221', '\222', '\223', '\224', '\225', '\226', '\227',
        '\230', '\231', '\232', '\233', '\234', '\235', '\236', '\237',
        '\240', '\241', '\242', '\243', '\244', '\245', '\246', '\247',
        '\250', '\251', '\252', '\253', '\254', '\255', '\256', '\257',
        '\260', '\261', '\262', '\263', '\264', '\265', '\266', '\267',
        '\270', '\271', '\272', '\273', '\274', '\275', '\276', '\277',
        '\300', '\301', '\302', '\303', '\304', '\305', '\306', '\307',
        '\310', '\311', '\312', '\313', '\314', '\315', '\316', '\317',
        '\320', '\321', '\322', '\323', '\324', '\325', '\326', '\327',
        '\330', '\331', '\332', '\333', '\334', '\335', '\336', '\337',
        '\340', '\341', '\342', '\343', '\344', '\345', '\346', '\347',
        '\350', '\351', '\352', '\353', '\354', '\355', '\356', '\357',
        '\360', '\361', '\362', '\363', '\364', '\365', '\366', '\367',
        '\370', '\371', '\372', '\373', '\374', '\375', '\376', '\377',
    },
    {
        '\000', '\000', '\000', '\000', '\000', '\000', '\000', '\000',
        '\000', '\000', '\000', '\000', '\000', '\000', '\000', '\000',
        '\000', '\000', '\000', '\000', '\000', '\000', '\000', '\000',
        '\000', '\000', '\000', '\000', '\000', '\000', '\000', '\000',
        '\000', '\000', '\000', '\000', '\000', '\000', '\000', '\000',
        '\001', '\000', '\000', '\000', '\000', '\000', '\000', '\000',
        '\000', '\000', '\000', '\000', '\000', '\000', '\000', '\000',
        '\000', '\000', '\000', '\000', '\000', '\000', '\000', '\000',
        '\000', '\000', '\000', '\000', '\000', '\000', '\000', '\000',
        '\000', '\000', '\000', '\000', '\000', '\000', '\000', '\000',
        '\000', '\000', '\000', '\000', '\000', '\000', '\000', '\000',
        '\000', '\000', '\000', '\000', '\000', '\000', '\000', '\000',
        '\000', '\000', '\000', '\000', '\000', '\000', '\000', '\000',
        '\000', '\000', '\000', '\000', '\000', '\000', '\000', '\000',
        '\000', '\000', '\000', '\000', '\000', '\000', '\000', '\000',
        '\000', '\000', '\000', '\000', '\000', '\000', '\000', '\000',
        '\000', '\000', '\000', '\000', '\000', '\000', '\000', '\000',
        '\000', '\000', '\000', '\000', '\000', '\000', '\000', '\000',
        '\000', '\000', '\000', '\000', '\000', '\000', '\000', '\000',
        '\000', '\000', '\000', '\000', '\000', '\000', '\000', '\000',
        '\000', '\000', '\000', '\000', '\000', '\000', '\000', '\000',
        '\000', '\000', '\000', '\000', '\000', '\000', '\000', '\000',
        '\000', '\000', '\000', '\000', '\000', '\000', '\000', '\000',
        '\000', '\000', '\000', '\000', '\000', '\000', '\000', '\000',
        '\000', '\000', '\000', '\000', '\000', '\000', '\000', '\000',
        '\000', '\000', '\000', '\000', '\000', '\000', '\000', '\000',
        '\000', '\000', '\000', '\000', '\000', '\000', '\000', '\000',
        '\000', '\000', '\000', '\000', '\000', '\000', '\000', '\000',
        '\000', '\000', '\000', '\000', '\000', '\000', '\000', '\000',
        '\000', '\000', '\000', '\000', '\000', '\000', '\000', '\000',
        '\000', '\000', '\000', '\000', '\000', '\000', '\000', '\000',
        '\000', '\000', '\000', '\000', '\000', '\000', '\000', '\000',
    },
    {
        '\000', '\000', '\000', '\000', '\000', '\000', '\000', '\000',
        '\000', '\000', '\000', '\000', '\000', '\000', '\000', '\000',
        '\000', '\000', '\000', '\000', '\000', '\000', '\000', '\000',
        '\000', '\000', '\000', '\000', '\000', '\000', '\000', '\000',
        '\000', '\000', '\000', '\000', '\000', '\000', '\000', '\000',
        '\000', '\001', '\000', '\000', '\000', '\000', '\000', '\000',
        '\000', '\000', '\000', '\000', '\000', '\000', '\000', '\000',
        '\000', '\000', '\000', '\000', '\000', '\000', '\000', '\000',
        '\000', '\000', '\000', '\000', '\000', '\000', '\000', '\000',
        '\000', '\000', '\000', '\000', '\000', '\000', '\000', '\000',
        '\000', '\000', '\000', '\000', '\000', '\000', '\000', '\000',
        '\000', '\000', '\000', '\000', '\000', '\000', '\000', '\000',
        '\000', '\000', '\000', '\000', '\000', '\000', '\000', '\000',
        '\000', '\000', '\000', '\000', '\000', '\000', '\000', '\000',
        '\000', '\000', '\000', '\000', '\000', '\000', '\000', '\000',
        '\000', '\000', '\000', '\000', '\000', '\000', '\000', '\000',
        '\000', '\000', '\000', '\000', '\000', '\000', '\000', '\000',
        '\000', '\000', '\000', '\000', '\000', '\000', '\000', '\000',
        '\000', '\000', '\000', '\000', '\000', '\000', '\000', '\000',
        '\000', '\000', '\000', '\000', '\000', '\000', '\000', '\000',
        '\000', '\000', '\000', '\000', '\000', '\000', '\000', '\000',
        '\000', '\000', '\000', '\000', '\000', '\000', '\000', '\000',
        '\000', '\000', '\000', '\000', '\000', '\000', '\000', '\000',
        '\000', '\000', '\000', '\000', '\000', '\000', '\000', '\000',
        '\000', '\000', '\000', '\000', '\000', '\000', '\000', '\000',
        '\000', '\000', '\000', '\000', '\000', '\000', '\000', '\000',
        '\000', '\000', '\000', '\000', '\000', '\000', '\000', '\000',
        '\000', '\000', '\000', '\000', '\000', '\000', '\000', '\000',
        '\000', '\000', '\000', '\000', '\000', '\000', '\000', '\000',
        '\000', '\000', '\000', '\000', '\000', '\000', '\000', '\000',
        '\000', '\000', '\000', '\000', '\000', '\000', '\000', '\000',
        '\000', '\000', '\000', '\000', '\000', '\000', '\000', '\000',
    },
    {
        '\000', '\000', '\000', '\000', '\000', '\000', '\000', '\000',
        '\000', '\000', '\000', '\000', '\000', '\000', '\000', '\000',
        '\000', '\000', '\000', '\000', '\000', '\000', '\000', '\000',
        '\000', '\000', '\000', '\000', '\000', '\000', '\000', '\000',
        '\000', '\000', '\000', '\000', '\000', '\000', '\000', '\000',
        '\000', '\000', '\000', '\000', '\000', '\000', '\000', '\000',
        '\000', '\000', '\000', '\000', '\000', '\000', '\000', '\000',
        '\000', '\000', '\000', '\000', '\000', '\000', '\000', '\000',
        '\000', '\000', '\000', '\000', '\000', '\000', '\000', '\000',
        '\000', '\000', '\000', '\000', '\000', '\000', '\000', '\000',
        '\000', '\000', '\000', '\000', '\000', '\000', '\000', '\000',
        '\000', '\000', '\000', '\000', '\001', '\000', '\000', '\000',
        '\000', '\000', '\000', '\000', '\000', '\000', '\000', '\000',
        '\000', '\000', '\000', '\000', '\000', '\000', '\000', '\000',
        '\000', '\000', '\000', '\000', '\000', '\000', '\000', '\000',
        '\000', '\000', '\000', '\000', '\000', '\000', '\000', '\000',
        '\000', '\000', '\000', '\000', '\000', '\000', '\000', '\000',
        '\000', '\000', '\000', '\000', '\000', '\000', '\000', '\000',
        '\000', '\000', '\000', '\000', '\000', '\000', '\000', '\000',
        '\000', '\000', '\000', '\000', '\000', '\000', '\000', '\000',
        '\000', '\000', '\000', '\000', '\000', '\000', '\000', '\000',
        '\000', '\000', '\000', '\000', '\000', '\000', '\000', '\000',
        '\000', '\000', '\000', '\000', '\000', '\000', '\000', '\000',
        '\000', '\000', '\000', '\000', '\000', '\000', '\000', '\000',
        '\000', '\000', '\000', '\000', '\000', '\000', '\000', '\000',
        '\000', '\000', '\000', '\000', '\000', '\000', '\000', '\000',
        '\000', '\000', '\000', '\000', '\000', '\000', '\000', '\000',
        '\000', '\000', '\000', '\000', '\000', '\000', '\000', '\000',
        '\000', '\000', '\000', '\000', '\000', '\000', '\000', '\000',
        '\000', '\000', '\000', '\000', '\000', '\000', '\000', '\000',
        '\000', '\000', '\000', '\000', '\000', '\000', '\000', '\000',
        '\000', '\000', '\000', '\000', '\000', '\000', '\000', '\000',
    },
    {
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\000', '\000', '\000', '\000', '\000', '\000', '\000', '\000',
        '\000', '\000', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
    },
    {
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\000', '\000', '\000', '\000', '\000', '\000', '\000', '\000',
        '\000', '\000', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\000', '\000', '\000', '\000', '\000', '\000', '\000',
        '\000', '\000', '\000', '\000', '\000', '\000', '\000', '\000',
        '\000', '\000', '\000', '\000', '\000', '\000', '\000', '\000',
        '\000', '\000', '\000', '\001', '\001', '\001', '\001', '\000',
        '\001', '\000', '\000', '\000', '\000', '\000', '\000', '\000',
        '\000', '\000', '\000', '\000', '\000', '\000', '\000', '\000',
        '\000', '\000', '\000', '\000', '\000', '\000', '\000', '\000',
        '\000', '\000', '\000', '\001', '\001', '\001', '\001', '\000',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
    },
    {
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\000', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
    },
    {
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
        '\001', '\001', '\001', '\001', '\001', '\001', '\001', '\001',
    },
    {
        '\000', '\000', '\002', '\003', '\004', '\005', '\006', '\007',
        '\010', '\001', '\012', '\013', '\014', '\015', '\016', '\017',
        '\020', '\021', '\022', '\023', '\024', '\025', '\026', '\027',
        '\030', '\031', '\032', '\033', '\034', '\035', '\036', '\037',
        '\040', '\041', '\042', '\043', '\044', '\045', '\046', '\047',
        '\050', '\051', '\052', '\053', '\054', '\055', '\056', '\057',
        '\060', '\061', '\062', '\063', '\064', '\065', '\066', '\067',
        '\070', '\071', '\072', '\073', '\074', '\075', '\076', '\077',
        '\100', '\141', '\142', '\143', '\144', '\145', '\146', '\147',
        '\150', '\151', '\152', '\153', '\154', '\155', '\156', '\157',
        '\160', '\161', '\162', '\163', '\164', '\165', '\166', '\167',
        '\170', '\171', '\172', '\133', '\134', '\135', '\136', '\137',
        '\140', '\141', '\142', '\143', '\144', '\145', '\146', '\147',
        '\150', '\151', '\152', '\153', '\154', '\155', '\156', '\157',
        '\160', '\161', '\162', '\163', '\164', '\165', '\166', '\167',
        '\170', '\171', '\172', '\173', '\174', '\175', '\176', '\177',
        '\200', '\201', '\202', '\203', '\204', '\205', '\206', '\207',
        '\210', '\211', '\212', '\213', '\214', '\215', '\216', '\217',
        '\220', '\221', '\222', '\223', '\224', '\225', '\226', '\227',
        '\230', '\231', '\232', '\233', '\234', '\235', '\236', '\237',
        '\240', '\241', '\242', '\243', '\244', '\245', '\246', '\247',
        '\250', '\251', '\252', '\253', '\254', '\255', '\256', '\257',
        '\260', '\261', '\262', '\263', '\264', '\265', '\266', '\267',
        '\270', '\271', '\272', '\273', '\274', '\275', '\276', '\277',
        '\300', '\301', '\302', '\303', '\304', '\305', '\306', '\307',
        '\310', '\311', '\312', '\313', '\314', '\315', '\316', '\317',
        '\320', '\321', '\322', '\323', '\324', '\325', '\326', '\327',
        '\330', '\331', '\332', '\333', '\334', '\335', '\336', '\337',
        '\340', '\341', '\342', '\343', '\344', '\345', '\346', '\347',
        '\350', '\351', '\352', '\353', '\354', '\355', '\356', '\357',
        '\360', '\361', '\362', '\363', '\364', '\365', '\366', '\367',
        '\370', '\371', '\372', '\373', '\374', '\375', '\376', '\377',
    },
    {
        '\000', '\000', '\002', '\003', '\004', '\005', '\006', '\007',
        '\010', '\012', '\012', '\013', '\014', '\015', '\016', '\017',
        '\020', '\021', '\022', '\023', '\024', '\025', '\026', '\027',
        '\030', '\031', '\032', '\033', '\034', '\035', '\036', '\037',
        '\040', '\041', '\042', '\043', '\001', '\045', '\046', '\047',
        '\050', '\051', '\052', '\053', '\054', '\055', '\056', '\057',
        '\060', '\061', '\062', '\063', '\064', '\065', '\066', '\067',
        '\070', '\071', '\072', '\073', '\074', '\075', '\076', '\077',
        '\100', '\141', '\142', '\143', '\144', '\145', '\146', '\147',
        '\150', '\151', '\152', '\153', '\154', '\155', '\156', '\157',
        '\160', '\161', '\162', '\163', '\164', '\165', '\166', '\167',
        '\170', '\171', '\172', '\133', '\134', '\135', '\136', '\137',
        '\140', '\141', '\142', '\143', '\144', '\145', '\146', '\147',
        '\150', '\151', '\152', '\153', '\154', '\155', '\156', '\157',
        '\160', '\161', '\162', '\163', '\164', '\165', '\166', '\167',
        '\170', '\171', '\172', '\173', '\174', '\175', '\176', '\177',
        '\200', '\201', '\202', '\203', '\204', '\205', '\206', '\207',
        '\210', '\211', '\212', '\213', '\214', '\215', '\216', '\217',
        '\220', '\221', '\222', '\223', '\224', '\225', '\226', '\227',
        '\230', '\231', '\232', '\233', '\234', '\235', '\236', '\237',
        '\240', '\241', '\242', '\243', '\244', '\245', '\246', '\247',
        '\250', '\251', '\252', '\253', '\254', '\255', '\256', '\257',
        '\260', '\261', '\262', '\263', '\264', '\265', '\266', '\267',
        '\270', '\271', '\272', '\273', '\274', '\275', '\276', '\277',
        '\300', '\301', '\302', '\303', '\304', '\305', '\306', '\307',
        '\310', '\311', '\312', '\313', '\314', '\315', '\316', '\317',
        '\320', '\321', '\322', '\323', '\324', '\325', '\326', '\327',
        '\330', '\331', '\332', '\333', '\334', '\335', '\336', '\337',
        '\340', '\341', '\342', '\343', '\344', '\345', '\346', '\347',
        '\350', '\351', '\352', '\353', '\354', '\355', '\356', '\357',
        '\360', '\361', '\362', '\363', '\364', '\365', '\366', '\367',
        '\370', '\371', '\372', '\373', '\374', '\375', '\376', '\377',
    },
    {
        '\000', '\000', '\002', '\003', '\004', '\005', '\006', '\007',
        '\010', '\012', '\012', '\013', '\014', '\015', '\016', '\017',
        '\020', '\021', '\022', '\023', '\024', '\025', '\026', '\027',
        '\030', '\031', '\032', '\033', '\034', '\035', '\036', '\037',
        '\040', '\041', '\042', '\043', '\044', '\045', '\046', '\047',
        '\050', '\051', '\052', '\053', '\054', '\055', '\056', '\057',
        '\060', '\061', '\062', '\063', '\064', '\065', '\066', '\067',
        '\070', '\071', '\072', '\073', '\074', '\075', '\076', '\077',
        '\100', '\141', '\142', '\143', '\144', '\145', '\146', '\147',
        '\150', '\151', '\152', '\153', '\154', '\155', '\156', '\157',
        '\160', '\161', '\162', '\163', '\164', '\165', '\166', '\167',
        '\170', '\171', '\172', '\133', '\134', '\135', '\136', '\137',
        '\140', '\141', '\142', '\143', '\144', '\145', '\146', '\147',
        '\150', '\151', '\152', '\153', '\154', '\155', '\156', '\157',
        '\160', '\161', '\162', '\163', '\164', '\165', '\166', '\167',
        '\170', '\171', '\172', '\173', '\001', '\175', '\176', '\177',
        '\200', '\201', '\202', '\203', '\204', '\205', '\206', '\207',
        '\210', '\211', '\212', '\213', '\214', '\215', '\216', '\217',
        '\220', '\221', '\222', '\223', '\224', '\225', '\226', '\227',
        '\230', '\231', '\232', '\233', '\234', '\235', '\236', '\237',
        '\240', '\241', '\242', '\243', '\244', '\245', '\246', '\247',
        '\250', '\251', '\252', '\253', '\254', '\255', '\256', '\257',
        '\260', '\261', '\262', '\263', '\264', '\265', '\266', '\267',
        '\270', '\271', '\272', '\273', '\274', '\275', '\276', '\277',
        '\300', '\301', '\302', '\303', '\304', '\305', '\306', '\307',
        '\310', '\311', '\312', '\313', '\314', '\315', '\316', '\317',
        '\320', '\321', '\322', '\323', '\324', '\325', '\326', '\327',
        '\330', '\331', '\332', '\333', '\334', '\335', '\336', '\337',
        '\340', '\341', '\342', '\343', '\344', '\345', '\346', '\347',
        '\350', '\351', '\352', '\353', '\354', '\355', '\356', '\357',
        '\360', '\361', '\362', '\363', '\364', '\365', '\366', '\367',
        '\370', '\371', '\372', '\373', '\374', '\375', '\376', '\377',
    },
};


#endif


/* EOF */ 
