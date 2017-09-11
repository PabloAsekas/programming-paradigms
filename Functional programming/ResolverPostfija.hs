-- Pablo Bermejo
-- https://github.com/PabloAsekas/

module ResolverPostfija where

import Pila
import Utilidades

--Resolver operación postfija

postfijaResultado :: [[String]] -> [String]
postfijaResultado [] = []
postfijaResultado (x:xs) = [operarPostfija x] ++ postfijaResultado xs

operarPostfija :: [String] -> String
operarPostfija lista = cima (foldl (\ pila x -> operarPostfijaAux pila x) pilaVacia lista)

operarPostfijaAux :: Pila String -> String -> Pila String
operarPostfijaAux pila x
	| (esDigito x) = apilar x pila
	| otherwise = apilar(operar (cima(desapilar pila)) (cima pila) x) (desapilar (desapilar pila))

operar :: String -> String -> String -> String
operar x y z
	| z == "+" = show((read x) + (read y))
	| z == "-" = show((read x) - (read y))
	| z == "*" = show((read x) * (read y))
	| z == "/" = show((read x) `div` (read y))
	| otherwise = show((read x) ^ (read y))