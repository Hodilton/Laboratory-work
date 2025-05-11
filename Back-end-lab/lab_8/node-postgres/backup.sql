--
-- PostgreSQL database dump
--

-- Dumped from database version 16.4 (Ubuntu 16.4-0ubuntu0.24.04.2)
-- Dumped by pg_dump version 16.4 (Ubuntu 16.4-0ubuntu0.24.04.2)

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

SET default_tablespace = '';

SET default_table_access_method = heap;

--
-- Name: merchants; Type: TABLE; Schema: public; Owner: barsuk
--

CREATE TABLE public.merchants (
    id integer NOT NULL,
    name character varying(30),
    email character varying(30)
);


ALTER TABLE public.merchants OWNER TO barsuk;

--
-- Name: merchants_id_seq; Type: SEQUENCE; Schema: public; Owner: barsuk
--

CREATE SEQUENCE public.merchants_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER SEQUENCE public.merchants_id_seq OWNER TO barsuk;

--
-- Name: merchants_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: barsuk
--

ALTER SEQUENCE public.merchants_id_seq OWNED BY public.merchants.id;


--
-- Name: merchants id; Type: DEFAULT; Schema: public; Owner: barsuk
--

ALTER TABLE ONLY public.merchants ALTER COLUMN id SET DEFAULT nextval('public.merchants_id_seq'::regclass);


--
-- Data for Name: merchants; Type: TABLE DATA; Schema: public; Owner: barsuk
--

COPY public.merchants (id, name, email) FROM stdin;
1	jake	jake@mail.com
\.


--
-- Name: merchants_id_seq; Type: SEQUENCE SET; Schema: public; Owner: barsuk
--

SELECT pg_catalog.setval('public.merchants_id_seq', 1, true);


--
-- Name: merchants merchants_pkey; Type: CONSTRAINT; Schema: public; Owner: barsuk
--

ALTER TABLE ONLY public.merchants
    ADD CONSTRAINT merchants_pkey PRIMARY KEY (id);


--
-- PostgreSQL database dump complete
--

