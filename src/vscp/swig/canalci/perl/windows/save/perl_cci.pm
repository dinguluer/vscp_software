# This file was automatically generated by SWIG
package perl_cci;
require Exporter;
require DynaLoader;
@ISA = qw(Exporter DynaLoader);
package perl_ccic;
bootstrap perl_cci;
package perl_cci;
@EXPORT = qw( );

# ---------- BASE METHODS -------------

package perl_cci;

sub TIEHASH {
    my ($classname,$obj) = @_;
    return bless $obj, $classname;
}

sub CLEAR { }

sub FIRSTKEY { }

sub NEXTKEY { }

sub FETCH {
    my ($self,$field) = @_;
    my $member_func = "swig_${field}_get";
    $self->$member_func();
}

sub STORE {
    my ($self,$field,$newval) = @_;
    my $member_func = "swig_${field}_set";
    $self->$member_func($newval);
}

sub this {
    my $ptr = shift;
    return tied(%$ptr);
}


# ------- FUNCTION WRAPPERS --------

package perl_cci;


############# Class : perl_cci::CCanalSuperWrapper ##############

package perl_cci::CCanalSuperWrapper;
@ISA = qw( perl_cci );
%OWNER = ();
%ITERATORS = ();
sub new {
    my $pkg = shift;
    my $self = perl_ccic::new_CCanalSuperWrapper(@_);
    bless $self, $pkg if defined($self);
}

sub DESTROY {
    return unless $_[0]->isa('HASH');
    my $self = tied(%{$_[0]});
    return unless defined $self;
    delete $ITERATORS{$self};
    if (exists $OWNER{$self}) {
        perl_ccic::delete_CCanalSuperWrapper($self);
        delete $OWNER{$self};
    }
}

*doCmdOpen = *perl_ccic::CCanalSuperWrapper_doCmdOpen;
*doCmdClose = *perl_ccic::CCanalSuperWrapper_doCmdClose;
*doCmdNOOP = *perl_ccic::CCanalSuperWrapper_doCmdNOOP;
*doCmdGetLevel = *perl_ccic::CCanalSuperWrapper_doCmdGetLevel;
*doCmdSend = *perl_ccic::CCanalSuperWrapper_doCmdSend;
*doCmdReceive = *perl_ccic::CCanalSuperWrapper_doCmdReceive;
*doCmdDataAvailable = *perl_ccic::CCanalSuperWrapper_doCmdDataAvailable;
*doCmdStatus = *perl_ccic::CCanalSuperWrapper_doCmdStatus;
*doCmdStatistics = *perl_ccic::CCanalSuperWrapper_doCmdStatistics;
*doCmdFilter = *perl_ccic::CCanalSuperWrapper_doCmdFilter;
*doCmdMask = *perl_ccic::CCanalSuperWrapper_doCmdMask;
*doCmdBaudrate = *perl_ccic::CCanalSuperWrapper_doCmdBaudrate;
*doCmdVersion = *perl_ccic::CCanalSuperWrapper_doCmdVersion;
*doCmdDLLVersion = *perl_ccic::CCanalSuperWrapper_doCmdDLLVersion;
*doCmdVendorString = *perl_ccic::CCanalSuperWrapper_doCmdVendorString;
*new_canalMsg = *perl_ccic::CCanalSuperWrapper_new_canalMsg;
*setCanalMsgId = *perl_ccic::CCanalSuperWrapper_setCanalMsgId;
*getCanalMsgId = *perl_ccic::CCanalSuperWrapper_getCanalMsgId;
*setCanalMsgFlags = *perl_ccic::CCanalSuperWrapper_setCanalMsgFlags;
*getCanalMsgFlags = *perl_ccic::CCanalSuperWrapper_getCanalMsgFlags;
*setCanalMsgExtendedId = *perl_ccic::CCanalSuperWrapper_setCanalMsgExtendedId;
*isCanalMsgExtendedId = *perl_ccic::CCanalSuperWrapper_isCanalMsgExtendedId;
*setCanalMsgStandardId = *perl_ccic::CCanalSuperWrapper_setCanalMsgStandardId;
*isCanalMsgStandardId = *perl_ccic::CCanalSuperWrapper_isCanalMsgStandardId;
*setCanalMsgRemoteFrame = *perl_ccic::CCanalSuperWrapper_setCanalMsgRemoteFrame;
*isCanalMsgRemoteFrame = *perl_ccic::CCanalSuperWrapper_isCanalMsgRemoteFrame;
*setCanalMsgObId = *perl_ccic::CCanalSuperWrapper_setCanalMsgObId;
*getCanalObId = *perl_ccic::CCanalSuperWrapper_getCanalObId;
*setCanalMsgSizeData = *perl_ccic::CCanalSuperWrapper_setCanalMsgSizeData;
*getCanalMsgSizeData = *perl_ccic::CCanalSuperWrapper_getCanalMsgSizeData;
*setCanalMsgData = *perl_ccic::CCanalSuperWrapper_setCanalMsgData;
*getCanalMsgData = *perl_ccic::CCanalSuperWrapper_getCanalMsgData;
*new_canalStatistics = *perl_ccic::CCanalSuperWrapper_new_canalStatistics;
*getCanalStatisticsReceiveFrames = *perl_ccic::CCanalSuperWrapper_getCanalStatisticsReceiveFrames;
*getCanalStatisticsTransmitFrames = *perl_ccic::CCanalSuperWrapper_getCanalStatisticsTransmitFrames;
*getCanalStatisticsReceiveData = *perl_ccic::CCanalSuperWrapper_getCanalStatisticsReceiveData;
*getCanalStatisticsTransmitData = *perl_ccic::CCanalSuperWrapper_getCanalStatisticsTransmitData;
*getCanalStatisticsOverruns = *perl_ccic::CCanalSuperWrapper_getCanalStatisticsOverruns;
*getCanalStatisticsBusWarnings = *perl_ccic::CCanalSuperWrapper_getCanalStatisticsBusWarnings;
*getCanalStatisticsBusOff = *perl_ccic::CCanalSuperWrapper_getCanalStatisticsBusOff;
*new_canalStatus = *perl_ccic::CCanalSuperWrapper_new_canalStatus;
*getcanalStatusChannelStatus = *perl_ccic::CCanalSuperWrapper_getcanalStatusChannelStatus;
*new_devItem = *perl_ccic::CCanalSuperWrapper_new_devItem;
*setdevItemId = *perl_ccic::CCanalSuperWrapper_setdevItemId;
*getdevItemId = *perl_ccic::CCanalSuperWrapper_getdevItemId;
*setdevItemRegId = *perl_ccic::CCanalSuperWrapper_setdevItemRegId;
*getdevItemRegId = *perl_ccic::CCanalSuperWrapper_getdevItemRegId;
*setdevItemName = *perl_ccic::CCanalSuperWrapper_setdevItemName;
*getdevItemName = *perl_ccic::CCanalSuperWrapper_getdevItemName;
*setdevItemPath = *perl_ccic::CCanalSuperWrapper_setdevItemPath;
*getdevItemPath = *perl_ccic::CCanalSuperWrapper_getdevItemPath;
*setdevItemDeviceString = *perl_ccic::CCanalSuperWrapper_setdevItemDeviceString;
*getdevItemDeviceString = *perl_ccic::CCanalSuperWrapper_getdevItemDeviceString;
*setdevItemFlags = *perl_ccic::CCanalSuperWrapper_setdevItemFlags;
*getdevItemFlags = *perl_ccic::CCanalSuperWrapper_getdevItemFlags;
*setdevItemInBufSize = *perl_ccic::CCanalSuperWrapper_setdevItemInBufSize;
*getdevItemInBufSize = *perl_ccic::CCanalSuperWrapper_getdevItemInBufSize;
*setdevItemOutBufSize = *perl_ccic::CCanalSuperWrapper_setdevItemOutBufSize;
*getdevItemOutBufSize = *perl_ccic::CCanalSuperWrapper_getdevItemOutBufSize;
*setdevItemFilter = *perl_ccic::CCanalSuperWrapper_setdevItemFilter;
*getdevItemFilter = *perl_ccic::CCanalSuperWrapper_getdevItemFilter;
*setdevItemMask = *perl_ccic::CCanalSuperWrapper_setdevItemMask;
*getdevItemMask = *perl_ccic::CCanalSuperWrapper_getdevItemMask;
sub DISOWN {
    my $self = shift;
    my $ptr = tied(%$self);
    delete $OWNER{$ptr};
}

sub ACQUIRE {
    my $self = shift;
    my $ptr = tied(%$self);
    $OWNER{$ptr} = 1;
}


############# Class : perl_cci::Shape ##############

package perl_cci::Shape;
@ISA = qw( perl_cci );
%OWNER = ();
%ITERATORS = ();
sub DESTROY {
    return unless $_[0]->isa('HASH');
    my $self = tied(%{$_[0]});
    return unless defined $self;
    delete $ITERATORS{$self};
    if (exists $OWNER{$self}) {
        perl_ccic::delete_Shape($self);
        delete $OWNER{$self};
    }
}

*swig_x_get = *perl_ccic::Shape_x_get;
*swig_x_set = *perl_ccic::Shape_x_set;
*swig_y_get = *perl_ccic::Shape_y_get;
*swig_y_set = *perl_ccic::Shape_y_set;
*move = *perl_ccic::Shape_move;
*area = *perl_ccic::Shape_area;
*perimeter = *perl_ccic::Shape_perimeter;
*nshapes = *perl_ccic::Shape_nshapes;
sub DISOWN {
    my $self = shift;
    my $ptr = tied(%$self);
    delete $OWNER{$ptr};
}

sub ACQUIRE {
    my $self = shift;
    my $ptr = tied(%$self);
    $OWNER{$ptr} = 1;
}


############# Class : perl_cci::Circle ##############

package perl_cci::Circle;
@ISA = qw( perl_cci perl_cci::Shape );
%OWNER = ();
%ITERATORS = ();
sub new {
    my $pkg = shift;
    my $self = perl_ccic::new_Circle(@_);
    bless $self, $pkg if defined($self);
}

*area = *perl_ccic::Circle_area;
*perimeter = *perl_ccic::Circle_perimeter;
sub DESTROY {
    return unless $_[0]->isa('HASH');
    my $self = tied(%{$_[0]});
    return unless defined $self;
    delete $ITERATORS{$self};
    if (exists $OWNER{$self}) {
        perl_ccic::delete_Circle($self);
        delete $OWNER{$self};
    }
}

sub DISOWN {
    my $self = shift;
    my $ptr = tied(%$self);
    delete $OWNER{$ptr};
}

sub ACQUIRE {
    my $self = shift;
    my $ptr = tied(%$self);
    $OWNER{$ptr} = 1;
}


############# Class : perl_cci::Square ##############

package perl_cci::Square;
@ISA = qw( perl_cci perl_cci::Shape );
%OWNER = ();
%ITERATORS = ();
sub new {
    my $pkg = shift;
    my $self = perl_ccic::new_Square(@_);
    bless $self, $pkg if defined($self);
}

*area = *perl_ccic::Square_area;
*perimeter = *perl_ccic::Square_perimeter;
sub DESTROY {
    return unless $_[0]->isa('HASH');
    my $self = tied(%{$_[0]});
    return unless defined $self;
    delete $ITERATORS{$self};
    if (exists $OWNER{$self}) {
        perl_ccic::delete_Square($self);
        delete $OWNER{$self};
    }
}

sub DISOWN {
    my $self = shift;
    my $ptr = tied(%$self);
    delete $OWNER{$ptr};
}

sub ACQUIRE {
    my $self = shift;
    my $ptr = tied(%$self);
    $OWNER{$ptr} = 1;
}


# ------- VARIABLE STUBS --------

package perl_cci;

*USE_SHM_INTERFACE = *perl_ccic::USE_SHM_INTERFACE;
*USE_DLL_INTERFACE = *perl_ccic::USE_DLL_INTERFACE;
*Shape_nshapes = *perl_ccic::Shape_nshapes;
1;
