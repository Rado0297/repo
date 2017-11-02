#lang racket
(define a 3)
(define b 1)
(define c 1)

;work with constants a, b, c
(define result 
	(- (* b b) (* 4 a c))
)

;wokr with random values for a, b, c
(define (discr a b c)
	(- (* b b) (* 4 a c))
)

;roots
(define (x1 a b c)
	(/ (+ (- b) (sqrt (- (* b b) (* 4 a c)))) (* 2 a))
)

(define (x2 a b c)
	(/ (- (- b) (sqrt (- (* b b) (* 4 a c)))) (* 2 a))
)