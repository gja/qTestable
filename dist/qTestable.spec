Name:           qTestable
Version:        0.0.8
Release:        8%{?dist}
Summary:        Library to write functional tests for Qt applications

Group:          Applications/Publishing
License:        ASL 2.0
URL:            http://github.com/gja/qTestable
Source0:        http://tejas.fedorapeople.org/%{name}/%{name}-%{version}.tar.gz
BuildRoot:      %{_tmppath}/%{name}-%{version}-%{release}-root-%(%{__id_u} -n)

Requires:  qt
Requires:  qjson

BuildRequires:  qt
BuildRequires:  cmake
BuildRequires:  qt-devel
BuildRequires:  xorg-x11-server-Xvfb
BuildRequires:  dbus
BuildRequires:  dbus-x11
BuildRequires:  qjson-devel


%description
qTestable is a library to help write Functional Tests for Qt


%package devel
Summary:        Development files for %{name} library
Group:          Development/Libraries
License:        ASL 2.0
Requires:       %{name} = %{version}-%{release}
Requires:       qt-devel

%description devel
Development files and documentation for the %{name} library.


%prep
%setup -q


%build
%cmake -DUSE_TEST=ON -DVERSION=%{version} \
%ifarch x86_64 ppc64 s390x sparc64
-DWANT_LIB64=1 \
%endif
.
make %{?_smp_mflags}


%check
xvfb-run ctest

%install
rm -rf $RPM_BUILD_ROOT
make install DESTDIR=$RPM_BUILD_ROOT


%clean
rm -rf $RPM_BUILD_ROOT

%post -p /sbin/ldconfig

%postun -p /sbin/ldconfig


%files
%defattr(-,root,root,-)
%{_libdir}/*.so.*
%{_datadir}/dbus-1/interfaces/*

%files devel
%defattr(-,root,root,-)
%{_libdir}/*.so
%{_includedir}/%{name}
%{_datadir}/cmake/Modules/Find%{name}.cmake
%{_libdir}/pkgconfig/*.pc


%changelog
* Fri Mar 18 2011 Tejas Dinkar <tejas@gja.in> - 0.0.8-8
- Adding the dbus xml
* Sun Feb 27 2011 Tejas Dinkar <tejas@gja.in> - 0.0.5-6
- Adding QJson to the RPM
* Sun Feb 27 2011 Tejas Dinkar <tejas@gja.in> - 0.0.4-4
- Letting the Version Be Driven by the RPM
* Sun Feb 27 2011 Tejas Dinkar <tejas@gja.in> - 0.0.3-3
- Added Unit Tests To The RPM
* Wed Feb 23 2011 Tejas Dinkar <tejas@gja.in> - 0.0.1-1
- Initial Checkin
