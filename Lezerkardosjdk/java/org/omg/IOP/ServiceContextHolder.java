package org.omg.IOP;

/**
* org/omg/IOP/ServiceContextHolder.java .
* Generated by the IDL-to-Java compiler (portable), version "3.2"
* from /build/openjdk-8-mHow25/openjdk-8-8u222-b10/src/corba/src/share/classes/org/omg/PortableInterceptor/IOP.idl
* Thursday, July 18, 2019 8:54:34 PM UTC
*/

public final class ServiceContextHolder implements org.omg.CORBA.portable.Streamable
{
  public org.omg.IOP.ServiceContext value = null;

  public ServiceContextHolder ()
  {
  }

  public ServiceContextHolder (org.omg.IOP.ServiceContext initialValue)
  {
    value = initialValue;
  }

  public void _read (org.omg.CORBA.portable.InputStream i)
  {
    value = org.omg.IOP.ServiceContextHelper.read (i);
  }

  public void _write (org.omg.CORBA.portable.OutputStream o)
  {
    org.omg.IOP.ServiceContextHelper.write (o, value);
  }

  public org.omg.CORBA.TypeCode _type ()
  {
    return org.omg.IOP.ServiceContextHelper.type ();
  }

}
