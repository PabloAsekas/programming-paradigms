-- Pablo Bermejo
-- https://github.com/PabloAsekas/

module InfijaAPostfija where

import Pila
import Utilidades

--De infija a postfija

deInfijaAPostFija :: [[String]] -> [[String]]
deInfijaAPostFija lista = foldl (\resultado x -> resultado ++ [infijaAPostfija x]) [] lista

infijaAPostfija :: [String] -> [String]
infijaAPostfija infija = vaciarUltimosElementosPila (separarTipos infija)

vaciarUltimosElementosPila :: (Pila String, [String]) -> [String]
vaciarUltimosElementosPila (p, pos)
	| esPilaVacia p = pos
	| otherwise = vaciarUltimosElementosPila (desapilar p, pos ++ [cima p])

separarTipos :: [String] -> (Pila String, [String])
separarTipos lista = foldl (\(p, pos) x -> separarTiposAux x (p, pos)) (pilaVacia, []) lista

separarTiposAux :: String -> (Pila String, [String]) -> (Pila String, [String])
separarTiposAux x (p, pos)
	| (esDigito x) = (p, pos ++ [x])
	| x == ")" = vaciarP (p, pos)
	| esPilaVacia p || valorF x > valorD (cima p) = (apilar x p, pos)
	| otherwise = vaciarPila (p, pos) x

vaciarP :: (Pila String, [String]) -> (Pila String, [String])
vaciarP (p, pos)
	| cima p == "(" = (desapilar p, pos)
	| otherwise = vaciarP (desapilar p, pos ++ [cima p])

vaciarPila :: (Pila String, [String]) -> String -> (Pila String, [String])
vaciarPila (p, pos) x
	| esPilaVacia p {--|| valorD (cima pila) < valorF x --}= (apilar x pilaVacia, pos)
	| otherwise = vaciarPila (desapilar p, pos ++ [cima p]) x

valorF :: String -> Int
valorF x
	| x == "+" || x == "-" = 1
	| x == "*" || x == "/" = 2
	| x == "^" = 3
	| x == "(" || x == ")" = 5

valorD :: String -> Int
valorD x
	| x == "+" || x == "-" = 1
	| x == "*" || x == "/" = 2
	| x == "^" = 4
	| x == "(" || x == ")" = 0