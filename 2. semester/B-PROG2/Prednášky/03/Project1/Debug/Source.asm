; Listing generated by Microsoft (R) Optimizing Compiler Version 19.12.25835.0 

	TITLE	C:\Users\speka\Desktop\PROG2\Prednasky\03\Project1\Project1\Source.c
	.686P
	.XMM
	include listing.inc
	.model	flat

INCLUDELIB MSVCRTD
INCLUDELIB OLDNAMES

PUBLIC	___local_stdio_printf_options
PUBLIC	__vfprintf_l
PUBLIC	_printf
PUBLIC	_dni_v_mesiaci
PUBLIC	_main
PUBLIC	??_C@_03PELOGHMK@?$CFi?6?$AA@			; `string'
EXTRN	__imp____acrt_iob_func:PROC
EXTRN	__imp__getchar:PROC
EXTRN	__imp____stdio_common_vfprintf:PROC
EXTRN	__RTC_CheckEsp:PROC
EXTRN	__RTC_InitBase:PROC
EXTRN	__RTC_Shutdown:PROC
_DATA	SEGMENT
COMM	?_OptionsStorage@?1??__local_stdio_printf_options@@9@9:QWORD							; `__local_stdio_printf_options'::`2'::_OptionsStorage
_DATA	ENDS
;	COMDAT rtc$TMZ
rtc$TMZ	SEGMENT
__RTC_Shutdown.rtc$TMZ DD FLAT:__RTC_Shutdown
rtc$TMZ	ENDS
;	COMDAT rtc$IMZ
rtc$IMZ	SEGMENT
__RTC_InitBase.rtc$IMZ DD FLAT:__RTC_InitBase
rtc$IMZ	ENDS
;	COMDAT ??_C@_03PELOGHMK@?$CFi?6?$AA@
CONST	SEGMENT
??_C@_03PELOGHMK@?$CFi?6?$AA@ DB '%i', 0aH, 00H		; `string'
CONST	ENDS
; Function compile flags: /Odtp /RTCsu /ZI
; File c:\users\speka\desktop\prog2\prednasky\03\project1\project1\source.c
;	COMDAT _main
_TEXT	SEGMENT
_i$1 = -8						; size = 4
_main	PROC						; COMDAT

; 37   : int main() {

	push	ebp
	mov	ebp, esp
	sub	esp, 204				; 000000ccH
	push	ebx
	push	esi
	push	edi
	lea	edi, DWORD PTR [ebp-204]
	mov	ecx, 51					; 00000033H
	mov	eax, -858993460				; ccccccccH
	rep stosd

; 38   : 	for (int i = 1; i <= 12; i++) {

	mov	DWORD PTR _i$1[ebp], 1
	jmp	SHORT $LN4@main
$LN2@main:
	mov	eax, DWORD PTR _i$1[ebp]
	add	eax, 1
	mov	DWORD PTR _i$1[ebp], eax
$LN4@main:
	cmp	DWORD PTR _i$1[ebp], 12			; 0000000cH
	jg	SHORT $LN3@main

; 39   : 		printf("%i\n", dni_v_mesiaci(i));

	mov	eax, DWORD PTR _i$1[ebp]
	push	eax
	call	_dni_v_mesiaci
	add	esp, 4
	push	eax
	push	OFFSET ??_C@_03PELOGHMK@?$CFi?6?$AA@
	call	_printf
	add	esp, 8

; 40   : }

	jmp	SHORT $LN2@main
$LN3@main:

; 41   : 	getchar();

	mov	esi, esp
	call	DWORD PTR __imp__getchar
	cmp	esi, esp
	call	__RTC_CheckEsp

; 42   : 	return 0;

	xor	eax, eax

; 43   : }

	pop	edi
	pop	esi
	pop	ebx
	add	esp, 204				; 000000ccH
	cmp	ebp, esp
	call	__RTC_CheckEsp
	mov	esp, ebp
	pop	ebp
	ret	0
_main	ENDP
_TEXT	ENDS
; Function compile flags: /Odtp /RTCsu /ZI
; File c:\users\speka\desktop\prog2\prednasky\03\project1\project1\source.c
;	COMDAT _dni_v_mesiaci
_TEXT	SEGMENT
_mesiac$ = 8						; size = 4
_dni_v_mesiaci PROC					; COMDAT

; 21   : int dni_v_mesiaci(int mesiac) {

	push	ebp
	mov	ebp, esp
	sub	esp, 192				; 000000c0H
	push	ebx
	push	esi
	push	edi
	lea	edi, DWORD PTR [ebp-192]
	mov	ecx, 48					; 00000030H
	mov	eax, -858993460				; ccccccccH
	rep stosd

; 22   : 	if (mesiac > 12 || mesiac<1) {

	cmp	DWORD PTR _mesiac$[ebp], 12		; 0000000cH
	jg	SHORT $LN4@dni_v_mesi
	cmp	DWORD PTR _mesiac$[ebp], 1
	jge	SHORT $LN2@dni_v_mesi
$LN4@dni_v_mesi:

; 23   : 		return 0;

	xor	eax, eax
	jmp	SHORT $LN1@dni_v_mesi

; 24   : 	}

	jmp	SHORT $LN1@dni_v_mesi
$LN2@dni_v_mesi:

; 25   : 	else {
; 26   : 		if (mesiac == 2) {

	cmp	DWORD PTR _mesiac$[ebp], 2
	jne	SHORT $LN5@dni_v_mesi

; 27   : 			return 28;

	mov	eax, 28					; 0000001cH
	jmp	SHORT $LN1@dni_v_mesi
$LN5@dni_v_mesi:

; 28   : 		}
; 29   : 		if (mesiac > 7) { mesiac -= 5; }

	cmp	DWORD PTR _mesiac$[ebp], 7
	jle	SHORT $LN6@dni_v_mesi
	mov	eax, DWORD PTR _mesiac$[ebp]
	sub	eax, 5
	mov	DWORD PTR _mesiac$[ebp], eax
$LN6@dni_v_mesi:

; 30   : 		if (mesiac % 2 == 0) {

	mov	eax, DWORD PTR _mesiac$[ebp]
	and	eax, -2147483647			; 80000001H
	jns	SHORT $LN10@dni_v_mesi
	dec	eax
	or	eax, -2					; fffffffeH
	inc	eax
$LN10@dni_v_mesi:
	test	eax, eax
	jne	SHORT $LN7@dni_v_mesi

; 31   : 			return 30;

	mov	eax, 30					; 0000001eH
	jmp	SHORT $LN1@dni_v_mesi

; 32   : 		}

	jmp	SHORT $LN1@dni_v_mesi
$LN7@dni_v_mesi:

; 33   : 		else { return 31; }

	mov	eax, 31					; 0000001fH
$LN1@dni_v_mesi:

; 34   : 	}
; 35   : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	0
_dni_v_mesiaci ENDP
_TEXT	ENDS
; Function compile flags: /Odtp /RTCsu /ZI
; File c:\program files (x86)\windows kits\10\include\10.0.16299.0\ucrt\stdio.h
;	COMDAT _printf
_TEXT	SEGMENT
__ArgList$ = -20					; size = 4
__Result$ = -8						; size = 4
__Format$ = 8						; size = 4
_printf	PROC						; COMDAT

; 952  :     {

	push	ebp
	mov	ebp, esp
	sub	esp, 216				; 000000d8H
	push	ebx
	push	esi
	push	edi
	lea	edi, DWORD PTR [ebp-216]
	mov	ecx, 54					; 00000036H
	mov	eax, -858993460				; ccccccccH
	rep stosd

; 953  :         int _Result;
; 954  :         va_list _ArgList;
; 955  :         __crt_va_start(_ArgList, _Format);

	lea	eax, DWORD PTR __Format$[ebp+4]
	mov	DWORD PTR __ArgList$[ebp], eax

; 956  :         _Result = _vfprintf_l(stdout, _Format, NULL, _ArgList);

	mov	eax, DWORD PTR __ArgList$[ebp]
	push	eax
	push	0
	mov	ecx, DWORD PTR __Format$[ebp]
	push	ecx
	mov	esi, esp
	push	1
	call	DWORD PTR __imp____acrt_iob_func
	add	esp, 4
	cmp	esi, esp
	call	__RTC_CheckEsp
	push	eax
	call	__vfprintf_l
	add	esp, 16					; 00000010H
	mov	DWORD PTR __Result$[ebp], eax

; 957  :         __crt_va_end(_ArgList);

	mov	DWORD PTR __ArgList$[ebp], 0

; 958  :         return _Result;

	mov	eax, DWORD PTR __Result$[ebp]

; 959  :     }

	pop	edi
	pop	esi
	pop	ebx
	add	esp, 216				; 000000d8H
	cmp	ebp, esp
	call	__RTC_CheckEsp
	mov	esp, ebp
	pop	ebp
	ret	0
_printf	ENDP
_TEXT	ENDS
; Function compile flags: /Odtp /RTCsu /ZI
; File c:\program files (x86)\windows kits\10\include\10.0.16299.0\ucrt\stdio.h
;	COMDAT __vfprintf_l
_TEXT	SEGMENT
__Stream$ = 8						; size = 4
__Format$ = 12						; size = 4
__Locale$ = 16						; size = 4
__ArgList$ = 20						; size = 4
__vfprintf_l PROC					; COMDAT

; 640  :     {

	push	ebp
	mov	ebp, esp
	sub	esp, 192				; 000000c0H
	push	ebx
	push	esi
	push	edi
	lea	edi, DWORD PTR [ebp-192]
	mov	ecx, 48					; 00000030H
	mov	eax, -858993460				; ccccccccH
	rep stosd

; 641  :         return __stdio_common_vfprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Stream, _Format, _Locale, _ArgList);

	mov	esi, esp
	mov	eax, DWORD PTR __ArgList$[ebp]
	push	eax
	mov	ecx, DWORD PTR __Locale$[ebp]
	push	ecx
	mov	edx, DWORD PTR __Format$[ebp]
	push	edx
	mov	eax, DWORD PTR __Stream$[ebp]
	push	eax
	call	___local_stdio_printf_options
	mov	ecx, DWORD PTR [eax+4]
	push	ecx
	mov	edx, DWORD PTR [eax]
	push	edx
	call	DWORD PTR __imp____stdio_common_vfprintf
	add	esp, 24					; 00000018H
	cmp	esi, esp
	call	__RTC_CheckEsp

; 642  :     }

	pop	edi
	pop	esi
	pop	ebx
	add	esp, 192				; 000000c0H
	cmp	ebp, esp
	call	__RTC_CheckEsp
	mov	esp, ebp
	pop	ebp
	ret	0
__vfprintf_l ENDP
_TEXT	ENDS
; Function compile flags: /Odtp /RTCsu /ZI
; File c:\program files (x86)\windows kits\10\include\10.0.16299.0\ucrt\corecrt_stdio_config.h
;	COMDAT ___local_stdio_printf_options
_TEXT	SEGMENT
___local_stdio_printf_options PROC			; COMDAT

; 85   :     {

	push	ebp
	mov	ebp, esp
	sub	esp, 192				; 000000c0H
	push	ebx
	push	esi
	push	edi
	lea	edi, DWORD PTR [ebp-192]
	mov	ecx, 48					; 00000030H
	mov	eax, -858993460				; ccccccccH
	rep stosd

; 86   :         static unsigned __int64 _OptionsStorage;
; 87   :         return &_OptionsStorage;

	mov	eax, OFFSET ?_OptionsStorage@?1??__local_stdio_printf_options@@9@9 ; `__local_stdio_printf_options'::`2'::_OptionsStorage

; 88   :     }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	0
___local_stdio_printf_options ENDP
_TEXT	ENDS
END
