# ¿Qué es CVSS V2?
CVSS es un framework abierto y de uso universal que permite clasificar una vulnerabilidad en función de su impacto y severidad.

CVSS es un sistema de puntuación que proporciona un método estándar y abierto para estimar el impacto de una vulnerabilidad y  que se compone tres grupos principales de métricas: 
+ Base 
+ Temporal 
+ Entorno (Environmental). 

** Cada uno de estos grupos se compone a su vez de un conjunto de métricas.

# 1 Grupo Base: 
Engloba las cualidades intrínsecas de una vulnerabilidad y que son independientes del tiempo y el entorno. Las métricas evaluadas en este grupo son:

## 1.1 Access Vector (AV). 
Valores: [L,A,N] 
+ Local 
+ Adjacent
+ Network

## 1.2 Access Complexity (AC). 
Valores [H,M,L] 
+ High
+ Medium
+ Low


## 1.3 Authentication (Au). 
Valores [M,S,N] 
+ Multiple
+ Single
+ None


## 1.4 Confidenciality Impact (C) . 
Valores [N,P,C] 
+ None
+ Partial
+ Complete

## 1.5 Integrity Impact (I)
Valores [N,P,C] 
+ None
+ Partial
+ Complete

## 1.6 Availability Impact (A). 
Valores [N,P,C] 
+ None
+ Partial
+ Complete

# 2 Grupo Temporal: 
Características de la vulnerabilidad que cambian en el tiempo. 

## 2.1 Exploitability (E). 
Valores: [U,POC,F,H,ND] 
+ Unproven
+ Proof-of-Concept
+ Functional Exploit
+ High
+ Not Defined)

## 2.2 Remediation Level (RL). 
Valores: [OF,TF,W,U,ND] 
+ Official Fix
+ Temporary Fix
+ Workaround
+ Unavailable
+ Not Defined

## 2.3 Report Confidence (RC). 
Valores: [UC,UR,C,ND] 
+ Unconfirmed
+ Uncorroborated
+ Confirmed
+ Not Defined

# 3 Grupo Environmental: 
Las características de la vulnerabilidad relacionadas con el entorno del usuario. 

## 3.1 Collateral Damage Potential (CDP). 
Valores: [N,L,LM,MH,H,ND] 
+ None
+ Low
+ Low Medium
+ Medium High
+ High
+ Not Defined

## 3.2 Target Distribution (TD). 
Valores: :[N,L,M,H,ND] 
+ None
+ Low
+ Medium
+ High
+ Not Defined

## 3.3 Security Requirements (CR, IR, AR). 
Valores: [L,M,H,ND] 
+ Low
+ Medium
+ High
+ Not Defined

# Referencias 

+ [Common Vulnerability Scoring System Calculator V3](https://nvd.nist.gov/vuln-metrics/cvss/v3-calculator)
+ [Métricas de evaluación de vulnerabilidades: CVSS 3.0](https://www.incibe-cert.es/blog/cvss3-0)