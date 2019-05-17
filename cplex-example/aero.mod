/* 
 * Modelagem em MathProg do problema 
 * "Questão 0.2 -- Problema da Empresa Aérea"
 *
 * Esse arquivo trás o modelo para o problema de reserva de passagens aéreas
 * que maximizem o lucro da companhia, apresentado na lista de exercícios 
 * "Lab 1 (2019)", disponível no slot dos dias 11 -- 17 de Março 
 * no moodle.inf.ufrgs.br.
 * 
 * Para resolver, execute a seguinte linha de comando.
 * Lembrando que a solução será gravada no arquivo ``aero.sol''.
 *
 * $ glpsol -m aero.mod -d aero.dat -o aero.sol
 *
 * Arquivo: aero.mod, modela o problema com dados de entrada completamente 
 * separados do modelo de programação linear. Confira o arquivo de dados
 * ``aero.dat''.
 *
 * Autor: Alberto Kummer
 * Modificado em: 22 Mar 2019
 *
 */

# Conjunto dos tipos de bilhetes.
set T;


# Conjunto dos trechos de viagem.
# O dimen 2 indica que cada elemento do conjunto é composto por uma tupla
# de dois itens.
set V dimen 2;


# Parâmetros do custo dos bilhetes, por trecho de viagem e tipo.
param custo {(c1,c2) in V, t in T};


# Parâmetros da quantidade máxima de bilhetes que podem ser reservados,
# para cada tipo de bilhete e trecho de viagem.
param maxBilhetes {(c1,c2) in V, t in T};


# Parâmetro de capacidade máxima da aeronave.
param capAero;


# Variáveis de decisão.
# Modelam quantos bilhetes de cada tipo devem ser reservados para cada trecho
# de viagem do problema. Já inclui as restrições de não negatividade.
var x {(c1,c2) in V, t in T} >= 0;


# Função objetivo.
# Supõe que o maior lucro provem dos bilhetes mais caros.
maximize lucro: sum {(c1,c2) in V, t in T} custo[c1,c2,t] * x[c1,c2,t];


# Restrições do número máximo de bilhetes que podem ser reservados.
s.t. limReservas {(c1,c2) in V, t in T}: x[c1,c2,t] <= maxBilhetes[c1,c2,t];


# Limita o nro de máximo de passageiros (possivelmente) embarcados no vôo
# com saída em Pelotas.
s.t. limPassageirosPel: sum{("Pel",c2) in V, t in T} x["Pel",c2,t] <= capAero;


# Limita o nro de máximo de passageiros (possivelmente) embarcados no vôo
# com saída em Porto Alegre.
s.t. limPassageirosPoa: sum{(c1,c2) in V, t in T: c2 != "Poa"} x[c1,c2,t] <= capAero;


# Fim do bloco de modelo.
end; 

