/**
 * Autogenerated by Thrift Compiler (0.9.1)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;
using System.IO;
using Thrift;
using Thrift.Collections;
using System.Runtime.Serialization;
using Thrift.Protocol;
using Thrift.Transport;

namespace cosh.c4
{
  public partial class C4Admin {
    public interface Iface {
      /// <summary>
      /// Executes a compaction
      /// </summary>
      void Compact();
      #if SILVERLIGHT
      IAsyncResult Begin_Compact(AsyncCallback callback, object state);
      void End_Compact(IAsyncResult asyncResult);
      #endif
      /// <summary>
      /// Cleares the column store
      /// </summary>
      void TabulaRasa();
      #if SILVERLIGHT
      IAsyncResult Begin_TabulaRasa(AsyncCallback callback, object state);
      void End_TabulaRasa(IAsyncResult asyncResult);
      #endif
      /// <summary>
      /// Saves the column store
      /// </summary>
      /// <param name="outputStream"></param>
      void Save(string outputStream);
      #if SILVERLIGHT
      IAsyncResult Begin_Save(AsyncCallback callback, object state, string outputStream);
      void End_Save(IAsyncResult asyncResult);
      #endif
      /// <summary>
      /// Loads the columnstore
      /// </summary>
      /// <param name="inputStream"></param>
      void Load(string inputStream);
      #if SILVERLIGHT
      IAsyncResult Begin_Load(AsyncCallback callback, object state, string inputStream);
      void End_Load(IAsyncResult asyncResult);
      #endif
      /// <summary>
      /// Shutdown
      /// </summary>
      void Shutdown();
      #if SILVERLIGHT
      IAsyncResult Begin_Shutdown(AsyncCallback callback, object state);
      void End_Shutdown(IAsyncResult asyncResult);
      #endif
    }

    public class Client : IDisposable, Iface {
      public Client(TProtocol prot) : this(prot, prot)
      {
      }

      public Client(TProtocol iprot, TProtocol oprot)
      {
        iprot_ = iprot;
        oprot_ = oprot;
      }

      protected TProtocol iprot_;
      protected TProtocol oprot_;
      protected int seqid_;

      public TProtocol InputProtocol
      {
        get { return iprot_; }
      }
      public TProtocol OutputProtocol
      {
        get { return oprot_; }
      }


      #region " IDisposable Support "
      private bool _IsDisposed;

      // IDisposable
      public void Dispose()
      {
        Dispose(true);
      }
      

      protected virtual void Dispose(bool disposing)
      {
        if (!_IsDisposed)
        {
          if (disposing)
          {
            if (iprot_ != null)
            {
              ((IDisposable)iprot_).Dispose();
            }
            if (oprot_ != null)
            {
              ((IDisposable)oprot_).Dispose();
            }
          }
        }
        _IsDisposed = true;
      }
      #endregion


      
      #if SILVERLIGHT
      public IAsyncResult Begin_Compact(AsyncCallback callback, object state)
      {
        return send_Compact(callback, state);
      }

      public void End_Compact(IAsyncResult asyncResult)
      {
        oprot_.Transport.EndFlush(asyncResult);
      }

      #endif

      /// <summary>
      /// Executes a compaction
      /// </summary>
      public void Compact()
      {
        #if !SILVERLIGHT
        send_Compact();

        #else
        var asyncResult = Begin_Compact(null, null);

        #endif
      }
      #if SILVERLIGHT
      public IAsyncResult send_Compact(AsyncCallback callback, object state)
      #else
      public void send_Compact()
      #endif
      {
        oprot_.WriteMessageBegin(new TMessage("Compact", TMessageType.Call, seqid_));
        Compact_args args = new Compact_args();
        args.Write(oprot_);
        oprot_.WriteMessageEnd();
        #if SILVERLIGHT
        return oprot_.Transport.BeginFlush(callback, state);
        #else
        oprot_.Transport.Flush();
        #endif
      }

      
      #if SILVERLIGHT
      public IAsyncResult Begin_TabulaRasa(AsyncCallback callback, object state)
      {
        return send_TabulaRasa(callback, state);
      }

      public void End_TabulaRasa(IAsyncResult asyncResult)
      {
        oprot_.Transport.EndFlush(asyncResult);
      }

      #endif

      /// <summary>
      /// Cleares the column store
      /// </summary>
      public void TabulaRasa()
      {
        #if !SILVERLIGHT
        send_TabulaRasa();

        #else
        var asyncResult = Begin_TabulaRasa(null, null);

        #endif
      }
      #if SILVERLIGHT
      public IAsyncResult send_TabulaRasa(AsyncCallback callback, object state)
      #else
      public void send_TabulaRasa()
      #endif
      {
        oprot_.WriteMessageBegin(new TMessage("TabulaRasa", TMessageType.Call, seqid_));
        TabulaRasa_args args = new TabulaRasa_args();
        args.Write(oprot_);
        oprot_.WriteMessageEnd();
        #if SILVERLIGHT
        return oprot_.Transport.BeginFlush(callback, state);
        #else
        oprot_.Transport.Flush();
        #endif
      }

      
      #if SILVERLIGHT
      public IAsyncResult Begin_Save(AsyncCallback callback, object state, string outputStream)
      {
        return send_Save(callback, state, outputStream);
      }

      public void End_Save(IAsyncResult asyncResult)
      {
        oprot_.Transport.EndFlush(asyncResult);
        recv_Save();
      }

      #endif

      /// <summary>
      /// Saves the column store
      /// </summary>
      /// <param name="outputStream"></param>
      public void Save(string outputStream)
      {
        #if !SILVERLIGHT
        send_Save(outputStream);
        recv_Save();

        #else
        var asyncResult = Begin_Save(null, null, outputStream);
        End_Save(asyncResult);

        #endif
      }
      #if SILVERLIGHT
      public IAsyncResult send_Save(AsyncCallback callback, object state, string outputStream)
      #else
      public void send_Save(string outputStream)
      #endif
      {
        oprot_.WriteMessageBegin(new TMessage("Save", TMessageType.Call, seqid_));
        Save_args args = new Save_args();
        args.OutputStream = outputStream;
        args.Write(oprot_);
        oprot_.WriteMessageEnd();
        #if SILVERLIGHT
        return oprot_.Transport.BeginFlush(callback, state);
        #else
        oprot_.Transport.Flush();
        #endif
      }

      public void recv_Save()
      {
        TMessage msg = iprot_.ReadMessageBegin();
        if (msg.Type == TMessageType.Exception) {
          TApplicationException x = TApplicationException.Read(iprot_);
          iprot_.ReadMessageEnd();
          throw x;
        }
        Save_result result = new Save_result();
        result.Read(iprot_);
        iprot_.ReadMessageEnd();
        if (result.__isset.ire) {
          throw result.Ire;
        }
        return;
      }

      
      #if SILVERLIGHT
      public IAsyncResult Begin_Load(AsyncCallback callback, object state, string inputStream)
      {
        return send_Load(callback, state, inputStream);
      }

      public void End_Load(IAsyncResult asyncResult)
      {
        oprot_.Transport.EndFlush(asyncResult);
        recv_Load();
      }

      #endif

      /// <summary>
      /// Loads the columnstore
      /// </summary>
      /// <param name="inputStream"></param>
      public void Load(string inputStream)
      {
        #if !SILVERLIGHT
        send_Load(inputStream);
        recv_Load();

        #else
        var asyncResult = Begin_Load(null, null, inputStream);
        End_Load(asyncResult);

        #endif
      }
      #if SILVERLIGHT
      public IAsyncResult send_Load(AsyncCallback callback, object state, string inputStream)
      #else
      public void send_Load(string inputStream)
      #endif
      {
        oprot_.WriteMessageBegin(new TMessage("Load", TMessageType.Call, seqid_));
        Load_args args = new Load_args();
        args.InputStream = inputStream;
        args.Write(oprot_);
        oprot_.WriteMessageEnd();
        #if SILVERLIGHT
        return oprot_.Transport.BeginFlush(callback, state);
        #else
        oprot_.Transport.Flush();
        #endif
      }

      public void recv_Load()
      {
        TMessage msg = iprot_.ReadMessageBegin();
        if (msg.Type == TMessageType.Exception) {
          TApplicationException x = TApplicationException.Read(iprot_);
          iprot_.ReadMessageEnd();
          throw x;
        }
        Load_result result = new Load_result();
        result.Read(iprot_);
        iprot_.ReadMessageEnd();
        if (result.__isset.ire) {
          throw result.Ire;
        }
        return;
      }

      
      #if SILVERLIGHT
      public IAsyncResult Begin_Shutdown(AsyncCallback callback, object state)
      {
        return send_Shutdown(callback, state);
      }

      public void End_Shutdown(IAsyncResult asyncResult)
      {
        oprot_.Transport.EndFlush(asyncResult);
      }

      #endif

      /// <summary>
      /// Shutdown
      /// </summary>
      public void Shutdown()
      {
        #if !SILVERLIGHT
        send_Shutdown();

        #else
        var asyncResult = Begin_Shutdown(null, null);

        #endif
      }
      #if SILVERLIGHT
      public IAsyncResult send_Shutdown(AsyncCallback callback, object state)
      #else
      public void send_Shutdown()
      #endif
      {
        oprot_.WriteMessageBegin(new TMessage("Shutdown", TMessageType.Call, seqid_));
        Shutdown_args args = new Shutdown_args();
        args.Write(oprot_);
        oprot_.WriteMessageEnd();
        #if SILVERLIGHT
        return oprot_.Transport.BeginFlush(callback, state);
        #else
        oprot_.Transport.Flush();
        #endif
      }

    }
    public class Processor : TProcessor {
      public Processor(Iface iface)
      {
        iface_ = iface;
        processMap_["Compact"] = Compact_Process;
        processMap_["TabulaRasa"] = TabulaRasa_Process;
        processMap_["Save"] = Save_Process;
        processMap_["Load"] = Load_Process;
        processMap_["Shutdown"] = Shutdown_Process;
      }

      protected delegate void ProcessFunction(int seqid, TProtocol iprot, TProtocol oprot);
      private Iface iface_;
      protected Dictionary<string, ProcessFunction> processMap_ = new Dictionary<string, ProcessFunction>();

      public bool Process(TProtocol iprot, TProtocol oprot)
      {
        try
        {
          TMessage msg = iprot.ReadMessageBegin();
          ProcessFunction fn;
          processMap_.TryGetValue(msg.Name, out fn);
          if (fn == null) {
            TProtocolUtil.Skip(iprot, TType.Struct);
            iprot.ReadMessageEnd();
            TApplicationException x = new TApplicationException (TApplicationException.ExceptionType.UnknownMethod, "Invalid method name: '" + msg.Name + "'");
            oprot.WriteMessageBegin(new TMessage(msg.Name, TMessageType.Exception, msg.SeqID));
            x.Write(oprot);
            oprot.WriteMessageEnd();
            oprot.Transport.Flush();
            return true;
          }
          fn(msg.SeqID, iprot, oprot);
        }
        catch (IOException)
        {
          return false;
        }
        return true;
      }

      public void Compact_Process(int seqid, TProtocol iprot, TProtocol oprot)
      {
        Compact_args args = new Compact_args();
        args.Read(iprot);
        iprot.ReadMessageEnd();
        iface_.Compact();
        return;
      }
      public void TabulaRasa_Process(int seqid, TProtocol iprot, TProtocol oprot)
      {
        TabulaRasa_args args = new TabulaRasa_args();
        args.Read(iprot);
        iprot.ReadMessageEnd();
        iface_.TabulaRasa();
        return;
      }
      public void Save_Process(int seqid, TProtocol iprot, TProtocol oprot)
      {
        Save_args args = new Save_args();
        args.Read(iprot);
        iprot.ReadMessageEnd();
        Save_result result = new Save_result();
        try {
          iface_.Save(args.OutputStream);
        } catch (InvalidRequestException ire) {
          result.Ire = ire;
        }
        oprot.WriteMessageBegin(new TMessage("Save", TMessageType.Reply, seqid)); 
        result.Write(oprot);
        oprot.WriteMessageEnd();
        oprot.Transport.Flush();
      }

      public void Load_Process(int seqid, TProtocol iprot, TProtocol oprot)
      {
        Load_args args = new Load_args();
        args.Read(iprot);
        iprot.ReadMessageEnd();
        Load_result result = new Load_result();
        try {
          iface_.Load(args.InputStream);
        } catch (InvalidRequestException ire) {
          result.Ire = ire;
        }
        oprot.WriteMessageBegin(new TMessage("Load", TMessageType.Reply, seqid)); 
        result.Write(oprot);
        oprot.WriteMessageEnd();
        oprot.Transport.Flush();
      }

      public void Shutdown_Process(int seqid, TProtocol iprot, TProtocol oprot)
      {
        Shutdown_args args = new Shutdown_args();
        args.Read(iprot);
        iprot.ReadMessageEnd();
        iface_.Shutdown();
        return;
      }
    }


    #if !SILVERLIGHT
    [Serializable]
    #endif
    public partial class Compact_args : TBase
    {

      public Compact_args() {
      }

      public void Read (TProtocol iprot)
      {
        TField field;
        iprot.ReadStructBegin();
        while (true)
        {
          field = iprot.ReadFieldBegin();
          if (field.Type == TType.Stop) { 
            break;
          }
          switch (field.ID)
          {
            default: 
              TProtocolUtil.Skip(iprot, field.Type);
              break;
          }
          iprot.ReadFieldEnd();
        }
        iprot.ReadStructEnd();
      }

      public void Write(TProtocol oprot) {
        TStruct struc = new TStruct("Compact_args");
        oprot.WriteStructBegin(struc);
        oprot.WriteFieldStop();
        oprot.WriteStructEnd();
      }

      public override string ToString() {
        StringBuilder sb = new StringBuilder("Compact_args(");
        sb.Append(")");
        return sb.ToString();
      }

    }


    #if !SILVERLIGHT
    [Serializable]
    #endif
    public partial class TabulaRasa_args : TBase
    {

      public TabulaRasa_args() {
      }

      public void Read (TProtocol iprot)
      {
        TField field;
        iprot.ReadStructBegin();
        while (true)
        {
          field = iprot.ReadFieldBegin();
          if (field.Type == TType.Stop) { 
            break;
          }
          switch (field.ID)
          {
            default: 
              TProtocolUtil.Skip(iprot, field.Type);
              break;
          }
          iprot.ReadFieldEnd();
        }
        iprot.ReadStructEnd();
      }

      public void Write(TProtocol oprot) {
        TStruct struc = new TStruct("TabulaRasa_args");
        oprot.WriteStructBegin(struc);
        oprot.WriteFieldStop();
        oprot.WriteStructEnd();
      }

      public override string ToString() {
        StringBuilder sb = new StringBuilder("TabulaRasa_args(");
        sb.Append(")");
        return sb.ToString();
      }

    }


    #if !SILVERLIGHT
    [Serializable]
    #endif
    public partial class Save_args : TBase
    {

      public string OutputStream { get; set; }

      public Save_args() {
      }

      public Save_args(string outputStream) : this() {
        this.OutputStream = outputStream;
      }

      public void Read (TProtocol iprot)
      {
        bool isset_outputStream = false;
        TField field;
        iprot.ReadStructBegin();
        while (true)
        {
          field = iprot.ReadFieldBegin();
          if (field.Type == TType.Stop) { 
            break;
          }
          switch (field.ID)
          {
            case 1:
              if (field.Type == TType.String) {
                OutputStream = iprot.ReadString();
                isset_outputStream = true;
              } else { 
                TProtocolUtil.Skip(iprot, field.Type);
              }
              break;
            default: 
              TProtocolUtil.Skip(iprot, field.Type);
              break;
          }
          iprot.ReadFieldEnd();
        }
        iprot.ReadStructEnd();
        if (!isset_outputStream)
          throw new TProtocolException(TProtocolException.INVALID_DATA);
      }

      public void Write(TProtocol oprot) {
        TStruct struc = new TStruct("Save_args");
        oprot.WriteStructBegin(struc);
        TField field = new TField();
        field.Name = "outputStream";
        field.Type = TType.String;
        field.ID = 1;
        oprot.WriteFieldBegin(field);
        oprot.WriteString(OutputStream);
        oprot.WriteFieldEnd();
        oprot.WriteFieldStop();
        oprot.WriteStructEnd();
      }

      public override string ToString() {
        StringBuilder sb = new StringBuilder("Save_args(");
        sb.Append("OutputStream: ");
        sb.Append(OutputStream);
        sb.Append(")");
        return sb.ToString();
      }

    }


    #if !SILVERLIGHT
    [Serializable]
    #endif
    public partial class Save_result : TBase
    {
      private InvalidRequestException _ire;

      public InvalidRequestException Ire
      {
        get
        {
          return _ire;
        }
        set
        {
          __isset.ire = true;
          this._ire = value;
        }
      }


      public Isset __isset;
      #if !SILVERLIGHT
      [Serializable]
      #endif
      public struct Isset {
        public bool ire;
      }

      public Save_result() {
      }

      public void Read (TProtocol iprot)
      {
        TField field;
        iprot.ReadStructBegin();
        while (true)
        {
          field = iprot.ReadFieldBegin();
          if (field.Type == TType.Stop) { 
            break;
          }
          switch (field.ID)
          {
            case 1:
              if (field.Type == TType.Struct) {
                Ire = new InvalidRequestException();
                Ire.Read(iprot);
              } else { 
                TProtocolUtil.Skip(iprot, field.Type);
              }
              break;
            default: 
              TProtocolUtil.Skip(iprot, field.Type);
              break;
          }
          iprot.ReadFieldEnd();
        }
        iprot.ReadStructEnd();
      }

      public void Write(TProtocol oprot) {
        TStruct struc = new TStruct("Save_result");
        oprot.WriteStructBegin(struc);
        TField field = new TField();

        if (this.__isset.ire) {
          if (Ire != null) {
            field.Name = "Ire";
            field.Type = TType.Struct;
            field.ID = 1;
            oprot.WriteFieldBegin(field);
            Ire.Write(oprot);
            oprot.WriteFieldEnd();
          }
        }
        oprot.WriteFieldStop();
        oprot.WriteStructEnd();
      }

      public override string ToString() {
        StringBuilder sb = new StringBuilder("Save_result(");
        sb.Append("Ire: ");
        sb.Append(Ire== null ? "<null>" : Ire.ToString());
        sb.Append(")");
        return sb.ToString();
      }

    }


    #if !SILVERLIGHT
    [Serializable]
    #endif
    public partial class Load_args : TBase
    {

      public string InputStream { get; set; }

      public Load_args() {
      }

      public Load_args(string inputStream) : this() {
        this.InputStream = inputStream;
      }

      public void Read (TProtocol iprot)
      {
        bool isset_inputStream = false;
        TField field;
        iprot.ReadStructBegin();
        while (true)
        {
          field = iprot.ReadFieldBegin();
          if (field.Type == TType.Stop) { 
            break;
          }
          switch (field.ID)
          {
            case 1:
              if (field.Type == TType.String) {
                InputStream = iprot.ReadString();
                isset_inputStream = true;
              } else { 
                TProtocolUtil.Skip(iprot, field.Type);
              }
              break;
            default: 
              TProtocolUtil.Skip(iprot, field.Type);
              break;
          }
          iprot.ReadFieldEnd();
        }
        iprot.ReadStructEnd();
        if (!isset_inputStream)
          throw new TProtocolException(TProtocolException.INVALID_DATA);
      }

      public void Write(TProtocol oprot) {
        TStruct struc = new TStruct("Load_args");
        oprot.WriteStructBegin(struc);
        TField field = new TField();
        field.Name = "inputStream";
        field.Type = TType.String;
        field.ID = 1;
        oprot.WriteFieldBegin(field);
        oprot.WriteString(InputStream);
        oprot.WriteFieldEnd();
        oprot.WriteFieldStop();
        oprot.WriteStructEnd();
      }

      public override string ToString() {
        StringBuilder sb = new StringBuilder("Load_args(");
        sb.Append("InputStream: ");
        sb.Append(InputStream);
        sb.Append(")");
        return sb.ToString();
      }

    }


    #if !SILVERLIGHT
    [Serializable]
    #endif
    public partial class Load_result : TBase
    {
      private InvalidRequestException _ire;

      public InvalidRequestException Ire
      {
        get
        {
          return _ire;
        }
        set
        {
          __isset.ire = true;
          this._ire = value;
        }
      }


      public Isset __isset;
      #if !SILVERLIGHT
      [Serializable]
      #endif
      public struct Isset {
        public bool ire;
      }

      public Load_result() {
      }

      public void Read (TProtocol iprot)
      {
        TField field;
        iprot.ReadStructBegin();
        while (true)
        {
          field = iprot.ReadFieldBegin();
          if (field.Type == TType.Stop) { 
            break;
          }
          switch (field.ID)
          {
            case 1:
              if (field.Type == TType.Struct) {
                Ire = new InvalidRequestException();
                Ire.Read(iprot);
              } else { 
                TProtocolUtil.Skip(iprot, field.Type);
              }
              break;
            default: 
              TProtocolUtil.Skip(iprot, field.Type);
              break;
          }
          iprot.ReadFieldEnd();
        }
        iprot.ReadStructEnd();
      }

      public void Write(TProtocol oprot) {
        TStruct struc = new TStruct("Load_result");
        oprot.WriteStructBegin(struc);
        TField field = new TField();

        if (this.__isset.ire) {
          if (Ire != null) {
            field.Name = "Ire";
            field.Type = TType.Struct;
            field.ID = 1;
            oprot.WriteFieldBegin(field);
            Ire.Write(oprot);
            oprot.WriteFieldEnd();
          }
        }
        oprot.WriteFieldStop();
        oprot.WriteStructEnd();
      }

      public override string ToString() {
        StringBuilder sb = new StringBuilder("Load_result(");
        sb.Append("Ire: ");
        sb.Append(Ire== null ? "<null>" : Ire.ToString());
        sb.Append(")");
        return sb.ToString();
      }

    }


    #if !SILVERLIGHT
    [Serializable]
    #endif
    public partial class Shutdown_args : TBase
    {

      public Shutdown_args() {
      }

      public void Read (TProtocol iprot)
      {
        TField field;
        iprot.ReadStructBegin();
        while (true)
        {
          field = iprot.ReadFieldBegin();
          if (field.Type == TType.Stop) { 
            break;
          }
          switch (field.ID)
          {
            default: 
              TProtocolUtil.Skip(iprot, field.Type);
              break;
          }
          iprot.ReadFieldEnd();
        }
        iprot.ReadStructEnd();
      }

      public void Write(TProtocol oprot) {
        TStruct struc = new TStruct("Shutdown_args");
        oprot.WriteStructBegin(struc);
        oprot.WriteFieldStop();
        oprot.WriteStructEnd();
      }

      public override string ToString() {
        StringBuilder sb = new StringBuilder("Shutdown_args(");
        sb.Append(")");
        return sb.ToString();
      }

    }

  }
}