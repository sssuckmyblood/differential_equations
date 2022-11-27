-- ---------------------------------------------------------------------------
--  Прогрмма: differential_equations.exe
--  Модуль:  Модуль создания базы данных
--  Автор:   Л. Б. Конопченко
--  Дата:    17.10.2022
--  Версия:  0.1
-- ---------------------------------------------------------------------------

-- Для создания базы данных нужно выполнить команду:

-- psql -f equation.sql -U postgres

DROP DATABASE IF EXISTS equation;
CREATE DATABASE equation
    WITH
    OWNER = postgres
    ENCODING = 'UTF8'
    TABLESPACE = pg_default
    CONNECTION LIMIT = -1
    IS_TEMPLATE = False;

COMMENT ON DATABASE equation
    IS 'differential_equations database';

\connect equation

create sequence if not exists equation_id_seq increment 1 start 0 minvalue 0 maxvalue 2147483647;

-- ---------------------------------------------------------------------------
-- Таблица "Уравнения"
-- ---------------------------------------------------------------------------

CREATE TABLE equation
(
    id integer NOT NULL DEFAULT nextval('equation_id_seq'::regclass),
    name_equ character varying(256),
    a_equ numeric,
    b_equ numeric,
    y0_equ numeric,
    accuracy numeric,
    date timestamp without time zone,
    PRIMARY KEY (id)
);

ALTER TABLE IF EXISTS equation
    OWNER to postgres;

COMMENT ON TABLE equation
    IS 'Table with equation parameters';

-- ---------------------------------------------------------------------------
-- Таблица "Метод Эйлера"
-- ---------------------------------------------------------------------------

CREATE TABLE method_euler
(
    id integer NOT NULL,
    x numeric,
    y numeric,
    exact numeric,
    error numeric

  
);

ALTER TABLE IF EXISTS method_euler
    OWNER to postgres;

COMMENT ON TABLE method_euler
    IS 'Table for euler method';

-- ---------------------------------------------------------------------------
-- Таблица "Метод Рунге-Кутта"
-- ---------------------------------------------------------------------------

CREATE TABLE method_runge
(
    id integer NOT NULL,
    x numeric,
    y numeric,
    exact numeric,
    error numeric
   
);

ALTER TABLE IF EXISTS method_runge
    OWNER to postgres;

COMMENT ON TABLE method_runge
    IS 'Table for runge method';

ALTER SEQUENCE IF EXISTS equation_id_seq OWNED BY equation.id;

ALTER TABLE equation
ADD CONSTRAINT equation_uni UNIQUE (name_equ,  a_equ, b_equ,  y0_equ, accuracy)
